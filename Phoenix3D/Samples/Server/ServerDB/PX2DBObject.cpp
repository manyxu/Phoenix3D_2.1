// PX2DBObject.cpp

#include "PX2DBObject.hpp"
#include "PX2ScopedCS.hpp"
#include "PX2System.hpp"
#include "PX2Memory.hpp"
#include "PX2Log.hpp"
using namespace PX2Server;
using namespace PX2;

//----------------------------------------------------------------------------
DBObject::DBObject() :
mMySQL_Result(0),
mMySQL_Row(0),
m_plength(0),
mIsInited(false),
m_effectrow(0),
m_ncolumnno(0)
{
	mysql_thread_init();

	mIsInited = (0!=mysql_init(&mMySQL));
}
//----------------------------------------------------------------------------
DBObject::~DBObject()
{
	if (mIsInited)
		mysql_close(&mMySQL);
}
//----------------------------------------------------------------------------
bool DBObject::Connect(const std::string &mysql_ip, 
	const std::string &mysql_user, const std::string &mysql_passwd,
	const std::string &mysql_db, int mysql_port)
{
	if (!mIsInited) return false;

	if (mysql_options(&mMySQL, MYSQL_SET_CHARSET_NAME, "utf8") != 0)
	{
		PX2_LOG_ERROR(" mysql_options error:%d ", mysql_errno(&mMySQL));
		return false;
	}

	unsigned int timeout = 10;
	if (mysql_options(&mMySQL, MYSQL_OPT_CONNECT_TIMEOUT, &timeout) != 0)
	{
		PX2_LOG_ERROR(" mysql_options error:%d ", mysql_errno(&mMySQL));
		return false;
	}

	if (mysql_real_connect(&mMySQL, mysql_ip.c_str(), mysql_user.c_str(),
		mysql_passwd.c_str(), mysql_db.c_str(), mysql_port, NULL,
		CLIENT_MULTI_STATEMENTS | CLIENT_MULTI_RESULTS) == 0)
	{
		PX2_LOG_ERROR("mysql_real_connect %s error:%d ", mysql_error(&mMySQL),
			mysql_errno(&mMySQL));
		return false;
	}

	mMySQL_IP = mysql_ip;
	mMySQL_User = mysql_user;
	mMySQL_Password = mysql_passwd;
	mMySQL_DB = mysql_db;
	mMySQL_Port = mysql_port;

	return true;
}
//----------------------------------------------------------------------------
bool DBObject::Execute(const std::string &sqlStr)
{
	EndFetch();

	m_ncolumnno = 0;
	m_vfiledlength.clear();
	m_plength = NULL;

	if (mysql_query(&mMySQL, sqlStr.c_str()) != 0)
	{
		PX2_LOG_ERROR("%s error:%d ", mysql_error(&mMySQL), mysql_errno(&mMySQL));

		if (mysql_errno(&mMySQL) == 2013)
		{
			mysql_close(&mMySQL);

			if (mysql_init(&mMySQL) != NULL &&
				Connect(mMySQL_IP, mMySQL_User, mMySQL_Password, mMySQL_DB, mMySQL_Port))
			{
				if (mysql_query(&mMySQL, sqlStr.c_str()) != 0)
				{
					PX2_LOG_ERROR("%s error:%d ", mysql_error(&mMySQL), mysql_errno(&mMySQL));
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	return StoreResult(true);
}
//----------------------------------------------------------------------------
bool DBObject::Fetch()
{
	mMySQL_Row = mysql_fetch_row(mMySQL_Result);
	if (0 == mMySQL_Row)
		return false;

	m_plength = mysql_fetch_lengths(mMySQL_Result);
	m_ncolumnno = 0;
	
	return true;
}
//----------------------------------------------------------------------------
void DBObject::EndFetch()
{
	if (mMySQL_Result)
	{
		mysql_free_result(mMySQL_Result);
		mMySQL_Result = 0;
	}

	while (mysql_next_result(&mMySQL) == 0)
	{
		mMySQL_Result = mysql_store_result(&mMySQL);
		if (mMySQL_Result)
		{
			mysql_free_result(mMySQL_Result);
			mMySQL_Result = 0;
		}
	}

	m_plength = 0;
}
//----------------------------------------------------------------------------
bool DBObject::StoreResult(bool storeType)
{
	if (storeType)
	{
		//全部抽取数据
		mMySQL_Result = mysql_store_result(&mMySQL);
		if (!mMySQL_Result)
		{
			if (mysql_errno(&mMySQL) != 0)
			{
				PX2_LOG_ERROR("mysql_store_result error:%d ", mysql_errno(&mMySQL));
				return false;
			}
			return true;
		}
	}
	else
	{
		mMySQL_Result = mysql_use_result(&mMySQL);
		if (!mMySQL_Result)
		{
			if (mysql_errno(&mMySQL) != 0)
			{
				PX2_LOG_ERROR("mysql_store_result error:%d ", mysql_errno(&mMySQL));
				return false;
			}
			return true;
		}
	}

	//unsigned int filedcount = mysql_num_fields( mMySQL_Result ) ;
	//MYSQL_FIELD* pfiled = NULL ;
	//for ( unsigned int i = 0 ; i< filedcount ; ++i )
	//{
	//	pfiled = mysql_fetch_field_direct( mMySQL_Result , i ) ;
	//	m_vfiledlength.push_back( pfiled->length );
	//}
	return true;
}
//----------------------------------------------------------------------------
int DBObject::GetAffectedRow()
{
	return (int)mysql_affected_rows(&mMySQL);
}
//----------------------------------------------------------------------------
DBObject& DBObject::operator >> (char &nVal)
{
	nVal = *mMySQL_Row[m_ncolumnno];
	++m_ncolumnno;
	return *this;
}
//----------------------------------------------------------------------------
DBObject& DBObject::operator >> (short &nVal)
{
	nVal = (short)atoi(mMySQL_Row[m_ncolumnno]);
	++m_ncolumnno;
	return *this;
}
//----------------------------------------------------------------------------
DBObject& DBObject::operator >> (long &nVal)
{
	nVal = atol(mMySQL_Row[m_ncolumnno]);
	++m_ncolumnno;
	return *this;
}
//----------------------------------------------------------------------------
DBObject& DBObject::operator >> (int &nVal)
{
	nVal = atoi(mMySQL_Row[m_ncolumnno]);
	++m_ncolumnno;
	return *this;
}
//----------------------------------------------------------------------------
DBObject& DBObject::operator >> (int64_t &i64Val)
{
	i64Val = _atoi64(mMySQL_Row[m_ncolumnno]);
	++m_ncolumnno;
	return *this;
}
//----------------------------------------------------------------------------
DBObject& DBObject::operator >> (std::string &strVal)
{
	strVal = mMySQL_Row[m_ncolumnno];
	++m_ncolumnno;
	return *this;
}
//----------------------------------------------------------------------------
void DBObject::GetBinaryData(char* buf, std::size_t &bufsize)
{
	int length = m_plength[m_ncolumnno];

	if (0!=mMySQL_Row[m_ncolumnno] && 0!=length)
	{
		memcpy(buf, mMySQL_Row[m_ncolumnno], length);
	}
	else
	{
		length = 0;
	}
	++m_ncolumnno;

	bufsize = length;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// DBPool
//----------------------------------------------------------------------------
DBPool::DBPool()
{
	if (mysql_library_init(0, 0, 0) == 0)
	{
		PX2_LOG_ERROR(" mysql_library_init success");
	}
	else
	{
		PX2_LOG_ERROR(" mysql_library_init failed");
	}
}
//----------------------------------------------------------------------------
DBPool::~DBPool()
{
	ScopedCS cs(&mMutex);

	std::map<int, DBObject*>::iterator iter = mPool.begin();
	for (; iter != mPool.end(); ++iter)
	{
		delete iter->second;
	}

	mPool.clear();
}
//----------------------------------------------------------------------------
DBObject* DBPool::GetDB(const std::string &mysql_ip, 
	const std::string &mysql_user, const std::string &mysql_passwd, 
	const std::string& mysql_db, int mysql_port)
{
	int curThreadID = System::GetCurrentThreadID();

	ScopedCS cs(&mMutex);
	
	std::map<int, DBObject*>::iterator iter = mPool.find(curThreadID);
	if (iter == mPool.end())
	{
		DBObject* obj = new0 DBObject();
		if (!obj->Connect(mysql_ip, mysql_user, mysql_passwd, mysql_db, mysql_port))
		{
			delete0(obj);
			return 0;
		}
		
		PX2_LOG_INFO("connect database success in thread id(%d)", curThreadID);

		mPool[curThreadID] = obj;

		return obj;
	}

	if (0 == iter->second)
	{
		DBObject* obj = new0 DBObject();
		if (!obj->Connect(mysql_ip, mysql_user, mysql_passwd, mysql_db, mysql_port))
		{
			delete0(obj);
			return 0;
		}

		PX2_LOG_INFO("connect database success in thread id(%d)", curThreadID);

		mPool[curThreadID] = obj;

		return obj;
	}

	return iter->second;
}
//----------------------------------------------------------------------------
bool DBPool::ConnectAllDB(const std::vector<int> &threadIDs, 
	const std::string& mysql_ip, const std::string& mysql_user,
	const std::string& mysql_passwd, const std::string& mysql_db, 
	int mysql_port)
{
	ScopedCS cs(&mMutex);

	for (size_t i = 0; i < threadIDs.size(); ++i)
	{
		std::map<int, DBObject*>::iterator iter = mPool.find(threadIDs[i]);

		if (iter == mPool.end() || 0==iter->second)
		{
			DBObject* obj = 0;
			int reConnCount = 3;

			while (reConnCount > 0)
			{
				obj = new0 DBObject();

				if (!obj->Connect(mysql_ip, mysql_user, mysql_passwd, mysql_db, mysql_port))
				{
					delete0(obj);
					obj = 0;
					reConnCount--;

					Sleep(10);
				}
				else
				{
					break;
				}
			}

			if (obj)
			{
				PX2_LOG_INFO("connect database success in thread id(%d)", threadIDs[i]);
			}

			mPool[threadIDs[i]] = obj;

			System::SleepSeconds(0.1f);
		}
	}
	return true;
}
//----------------------------------------------------------------------------
void DBPool::KeepLive(double appTime)
{
	PX2_UNUSED(appTime);

	/*_*/
}
//----------------------------------------------------------------------------