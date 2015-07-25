// PX2DataBaseMySQL.cpp

#ifdef PX2SERVER_DB_USE_MYSQL

#include "PX2DataBaseMySQL.hpp"
#include "PX2Log.hpp"
#include <errmsg.h>
using namespace PX2;

//-----------------------------------------------------------------------------
DataBaseMySQL::DataBaseMySQL()
{
	if (!mysql_init(&mHandle))
	{
		PX2_LOG_INFO("Failed to initialize MySQL connection handle.");
		return;
	}

	mIsConnected = true;
}
//-----------------------------------------------------------------------------
DataBaseMySQL::~DataBaseMySQL()
{
	mysql_close(&mHandle);
}
//-----------------------------------------------------------------------------
bool DataBaseMySQL::Connect(const std::string &mysql_ip,
	const std::string &mysql_user, const std::string &mysql_passwd,
	const std::string &mysql_db, int mysql_port)
{
	if (mysql_real_connect(&mHandle, mysql_ip.c_str(), mysql_user.c_str(),
		mysql_passwd.c_str(), mysql_db.c_str(), mysql_port, NULL,
		CLIENT_MULTI_STATEMENTS | CLIENT_MULTI_RESULTS) == 0)
	{
		PX2_LOG_ERROR("mysql_real_connect %s error:%d ", mysql_error(&mHandle),
			mysql_errno(&mHandle));
		return false;
	}

	my_bool reconnect = true;
	mysql_options(&mHandle, MYSQL_OPT_RECONNECT, &reconnect);

	mIsConnected = true;

	return true;
}
//-----------------------------------------------------------------------------
bool DataBaseMySQL::GetParam(DBParam param)
{
	switch (param)
	{
	case DBPARAM_MULTIINSERT:
		return true;
		break;
	default:
		return false;
	}
}
//-----------------------------------------------------------------------------
bool DataBaseMySQL::BeginTransaction()
{
	return ExecuteQuery("BEGIN");
}
//-----------------------------------------------------------------------------
bool DataBaseMySQL::Rollback()
{
	if (!mIsConnected) return false;

#ifdef __DEBUG_SQL__
	std::cout << "ROLLBACK" << std::endl;
#endif

	if (mysql_rollback(&mHandle) != 0)
	{
		std::cout << "mysql_rollback(): MYSQL ERROR: " << mysql_error(&mHandle) << std::endl;
		return false;
	}

	return true;
}
//-----------------------------------------------------------------------------
bool DataBaseMySQL::Commit()
{
	if (!mIsConnected) return false;

#ifdef __DEBUG_SQL__
	std::cout << "COMMIT" << std::endl;
#endif
	if (mysql_commit(&mHandle) != 0)
	{
		std::cout << "mysql_commit(): MYSQL ERROR: " << mysql_error(&mHandle) << std::endl;
		return false;
	}

	return true;
}
//-----------------------------------------------------------------------------
bool DataBaseMySQL::ExecuteQuery(const std::string &query)
{
	if (!mIsConnected) return false;

#ifdef __DEBUG_SQL__
	std::cout << "MYSQL QUERY: " << query << std::endl;
#endif

	bool state = true;

	// executes the query
	if (mysql_real_query(&mHandle, query.c_str(),
		(unsigned long)query.length()) != 0)
	{
		std::cout << "mysql_real_query(): " << query.substr(0, 256) << ": MYSQL ERROR: " << mysql_error(&mHandle) << std::endl;
		int error = mysql_errno(&mHandle);

		if (error == CR_SERVER_LOST || error == CR_SERVER_GONE_ERROR)
		{
			mIsConnected = false;
		}

		state = false;
	}

	// we should call that every time as someone would call executeQuery('SELECT...')
	// as it is described in MySQL manual: "it doesn't hurt" :P
	MYSQL_RES* result = mysql_store_result(&mHandle);

	if (result)
		mysql_free_result(result);

	return state;
}
//-----------------------------------------------------------------------------
int64_t DataBaseMySQL::GetLastInsertedRowID()
{
	return (uint64_t)mysql_insert_id(&mHandle);
}
//-----------------------------------------------------------------------------
DBResult *DataBaseMySQL::StoreQuery(const std::string &query)
{
	if (!mIsConnected) return false;

#ifdef __DEBUG_SQL__
	std::cout << "MYSQL QUERY: " << query << std::endl;
#endif

	// executes the query
	if (mysql_real_query(&mHandle, query.c_str(),
		(unsigned long)query.length()) != 0)
	{
		std::cout << "mysql_real_query(): " << query << ": MYSQL ERROR: " << mysql_error(&mHandle) << std::endl;
		int error = mysql_errno(&mHandle);

		if (error == CR_SERVER_LOST || error == CR_SERVER_GONE_ERROR)
		{
			mIsConnected = false;
		}

	}

	// we should call that every time as someone would call executeQuery('SELECT...')
	// as it is described in MySQL manual: "it doesn't hurt" :P
	MYSQL_RES* result = mysql_store_result(&mHandle);

	// error occured
	if (!result)
	{
		std::cout << "mysql_store_result(): " << query.substr(0, 256) << ": MYSQL ERROR: " << mysql_error(&mHandle) << std::endl;
		int error = mysql_errno(&mHandle);

		if (error == CR_SERVER_LOST || error == CR_SERVER_GONE_ERROR)
		{
			mIsConnected = false;
		}

		return 0;
	}

	// retriving results of query
	DBResult* res = new0 MySQLResult(result);
	return VerifyResult(res);
}
//-----------------------------------------------------------------------------
std::string DataBaseMySQL::EscapeString(const std::string &s)
{
	return EscapeBlob(s.c_str(), (uint32_t)s.length());
}
//-----------------------------------------------------------------------------
std::string DataBaseMySQL::EscapeBlob(const char *s, uint32_t length)
{
	// remember about quoiting even an empty string!
	if (!s) return std::string("''");

	// the worst case is 2n + 1
	char* output = new char[length * 2 + 1];

	// quotes escaped string and frees temporary buffer
	mysql_real_escape_string(&mHandle, output, s, length);
	std::string r = "'";
	r += output;
	r += "'";
	delete[] output;

	return r;
}
//-----------------------------------------------------------------------------
void DataBaseMySQL::FreeResult(DBResult *res)
{
	delete (MySQLResult*)res;
}
//-----------------------------------------------------------------------------
int64_t DataBaseMySQL::GetLastInsertID()
{
	return (uint64_t)mysql_insert_id(&mHandle);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// MySQLResult
//-----------------------------------------------------------------------------
MySQLResult::MySQLResult(MYSQL_RES* res)
{
	mHandle = res;
	mRow = 0;
	mListNames.clear();

	int32_t i = 0;
	MYSQL_FIELD* field = mysql_fetch_field(mHandle);
	while (field)
	{
		mListNames[field->name] = i;
		i++;

		field = mysql_fetch_field(mHandle);
	}
}
//-----------------------------------------------------------------------------
MySQLResult::~MySQLResult()
{
	mysql_free_result(mHandle);
}
//-----------------------------------------------------------------------------
int32_t MySQLResult::GetDataInt(const std::string &s)
{
	ListNames_t::iterator it = mListNames.find(s);
	if (it != mListNames.end())
	{
		if (mRow[it->second] == 0)
		{
			return 0;
		}
		else
		{
			return atoi(mRow[it->second]);
		}
	}

	std::cout << "Error during GetDataInt(" << s << ")." << std::endl;

	return 0; // Failed
}
//-----------------------------------------------------------------------------
int64_t MySQLResult::GetDataLong(const std::string &s)
{
	ListNames_t::iterator it = mListNames.find(s);
	if (it != mListNames.end())
	{
		if (mRow[it->second] == 0)
		{
			return 0;
		}
		else
		{
			return _atoi64(mRow[it->second]);
		}
	}

	std::cout << "Error during getDataLong(" << s << ")." << std::endl;

	return 0; // Failed
}
//-----------------------------------------------------------------------------
std::string MySQLResult::GetDataString(const std::string &s)
{
	ListNames_t::iterator it = mListNames.find(s);
	if (it != mListNames.end())
	{
		if (mRow[it->second] == 0)
		{
			return std::string("");
		}
		else
		{
			return std::string(mRow[it->second]);
		}
	}

	std::cout << "Error during getDataString(" << s << ")." << std::endl;

	return std::string(""); // Failed
}
//-----------------------------------------------------------------------------
const char* MySQLResult::GetDataStream(const std::string &s, 
	unsigned long &size)
{
	ListNames_t::iterator it = mListNames.find(s);
	if (it != mListNames.end())
	{
		if (mRow[it->second] == NULL)
		{
			size = 0;
			return 0;
		}
		else
		{
			size = mysql_fetch_lengths(mHandle)[it->second];
			return mRow[it->second];
		}
	}

	std::cout << "Error during getDataStream(" << s << ")." << std::endl;
	size = 0;

	return 0;
}
//-----------------------------------------------------------------------------
bool MySQLResult::Next()
{
	mRow = mysql_fetch_row(mHandle);
	return mRow != 0;
}
//-----------------------------------------------------------------------------

#endif