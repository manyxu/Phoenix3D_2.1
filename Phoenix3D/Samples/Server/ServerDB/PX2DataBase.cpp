// PX2DataBase.cpp

#include "PX2DataBase.hpp"
using namespace PX2;

//-----------------------------------------------------------------------------
DataBase::DataBase() :
mIsConnected(false)
{
}
//-----------------------------------------------------------------------------
DataBase::~DataBase()
{
}
//-----------------------------------------------------------------------------
bool DataBase::Connect(const std::string &mysql_ip,
	const std::string &mysql_user, const std::string &mysql_passwd,
	const std::string &mysql_db, int mysql_port)
{
	PX2_UNUSED(mysql_ip);
	PX2_UNUSED(mysql_user);
	PX2_UNUSED(mysql_passwd);
	PX2_UNUSED(mysql_db);
	PX2_UNUSED(mysql_port);

	return false;
}
//-----------------------------------------------------------------------------
bool DataBase::GetParam(DBParam param) 
{
	PX2_UNUSED(param);

	return false;
}
//-----------------------------------------------------------------------------
bool DataBase::BeginTransaction()
{
	return 0; 
}
//-----------------------------------------------------------------------------
bool DataBase::Rollback()
{
	return 0; 
}
//-----------------------------------------------------------------------------
bool DataBase::Commit()
{
	return 0;
}
//-----------------------------------------------------------------------------
bool DataBase::ExecuteQuery(const std::string &query)
{
	PX2_UNUSED(query);

	return false;
}
//-----------------------------------------------------------------------------
int64_t DataBase::GetLastInsertedRowID()
{
	return 0;
}
//-----------------------------------------------------------------------------
DBResult *DataBase::StoreQuery(const std::string &query)
{
	PX2_UNUSED(query);

	return 0;
}
//-----------------------------------------------------------------------------
std::string DataBase::EscapeString(const std::string &s)
{
	PX2_UNUSED(s);

	return "''";
}
//-----------------------------------------------------------------------------
std::string DataBase::EscapeBlob(const char *s, uint32_t length)
{
	PX2_UNUSED(s);
	PX2_UNUSED(length);

	return "''";
}
//-----------------------------------------------------------------------------
void DataBase::FreeResult(DBResult *res)
{
	PX2_UNUSED(res);
}
//-----------------------------------------------------------------------------
int64_t DataBase::GetLastInsertID()
{
	return 0;
}
//-----------------------------------------------------------------------------
std::string DataBase::GetStringComparer()
{
	return "= ";
}
//-----------------------------------------------------------------------------
std::string DataBase::GetUpdateLimiter()
{
	return " LIMIT 1;";
}
//-----------------------------------------------------------------------------
DBResult* DataBase::VerifyResult(DBResult* result)
{
	if (!result->Next())
	{
		FreeResult(result);

		return 0;
	}
	else
	{
		return result;
	}
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// DBInsert
//-----------------------------------------------------------------------------
DBInsert::DBInsert(DataBase* db) :
mDataBase(db)
{
	mNumRows = 0;
	mIsMultiLine = mDataBase->GetParam(DBPARAM_MULTIINSERT) != 0;
}
//-----------------------------------------------------------------------------
DBInsert::~DBInsert()
{
}
//-----------------------------------------------------------------------------
DBInsert::DBInsert() :
mNumRows(0),
mIsMultiLine(false)
{
}
//-----------------------------------------------------------------------------
void DBInsert::SetQuery(const std::string& query)
{
	mQuery = query;
	mBuffer = "";
	mNumRows = 0;
}
//-----------------------------------------------------------------------------
bool DBInsert::AddRow(const std::string& row)
{
	if (mIsMultiLine)
	{
		mNumRows++;

		size_t size = mBuffer.length();

		// adds new row to buffer
		if (size == 0)
		{
			mBuffer = "(" + row + ")";
		}
		else if (size > 8192)
		{
			if (!Execute())
				return false;

			mBuffer = "(" + row + ")";
		}
		else
		{
			mBuffer += ",(" + row + ")";
		}

		return true;
	}
	else
	{
		// executes INSERT for current row
		return mDataBase->ExecuteQuery(mQuery + "(" + row + ")");
	}
}
//-----------------------------------------------------------------------------
bool DBInsert::AddRow(std::stringstream& row)
{
	bool ret = AddRow(row.str());
	row.str("");

	return ret;
}
//-----------------------------------------------------------------------------
bool DBInsert::Execute()
{
	if (mIsMultiLine && mBuffer.length() > 0)
	{
		if (0 == mNumRows)
		{
			//no rows to execute
			return true;
		}

		mNumRows = 0;

		// executes buffer
		bool res = mDataBase->ExecuteQuery(mQuery + mBuffer);

		mBuffer = "";

		return res;
	}
	else
	{
		// INSERTs were executed on-fly
		return true;
	}
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// DBResult
//-----------------------------------------------------------------------------
DBResult::DBResult()
{
}
//-----------------------------------------------------------------------------
DBResult::~DBResult()
{
}
//-----------------------------------------------------------------------------
int32_t DBResult::GetDataInt(const std::string &s) 
{
	PX2_UNUSED(s);

	return 0; 
}
//-----------------------------------------------------------------------------
int64_t DBResult::GetDataLong(const std::string &s)
{
	PX2_UNUSED(s);

	return 0; 
}
//-----------------------------------------------------------------------------
std::string DBResult::GetDataString(const std::string &s)
{
	PX2_UNUSED(s);

	return "''"; 
}
//-----------------------------------------------------------------------------
const char* DBResult::GetDataStream(const std::string &s, unsigned long &size)
{
	PX2_UNUSED(s);
	PX2_UNUSED(size);

	return 0;
}
//-----------------------------------------------------------------------------
bool DBResult::Next()
{ 
	return false;
};
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// DBQueryStream
//-----------------------------------------------------------------------------
Mutex DBQueryStream::sDataBaseLock;
//-----------------------------------------------------------------------------
DBQueryStream::DBQueryStream()
{
}
//-----------------------------------------------------------------------------
DBQueryStream::~DBQueryStream()
{
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
DBTransaction::DBTransaction(DataBase* database) :
mDatabase(database)
{
	mState = STATE_NO_START;
}
//-----------------------------------------------------------------------------
DBTransaction::~DBTransaction()
{
	if (STATE_START == mState)
	{
		mDatabase->Rollback();
	}
}
//-----------------------------------------------------------------------------
bool DBTransaction::Begin()
{
	mState = STATE_START;

	return mDatabase->BeginTransaction();
}
//-----------------------------------------------------------------------------
bool DBTransaction::Commit()
{
	if (mState == STATE_START)
	{
		mState = STEATE_COMMIT;

		return mDatabase->Commit();
	}
	else
	{
		return false;
	}
}
//-----------------------------------------------------------------------------