// PX2DataBaseMySQL.hpp

#ifndef PX2DATABASEMYSQL_HPP
#define PX2DATABASEMYSQL_HPP

#ifdef PX2SERVER_DB_USE_MYSQL

#include "PX2NetPre.hpp"
#include "PX2DataBase.hpp"

#include "mysql.h"

namespace PX2
{

	class DataBaseMySQL : public DataBase
	{
	public:
		DataBaseMySQL();
		virtual ~DataBaseMySQL();

		virtual bool Connect(const std::string &mysql_ip,
			const std::string &mysql_user, const std::string &mysql_passwd,
			const std::string &mysql_db, int mysql_port);

		virtual bool GetParam(DBParam param);

	protected:
		virtual bool BeginTransaction();
		virtual bool Rollback();
		virtual bool Commit();

	public:
		virtual bool ExecuteQuery(const std::string &query);
		virtual int64_t GetLastInsertedRowID();

		virtual DBResult *StoreQuery(const std::string &query);

		virtual std::string EscapeString(const std::string &s);
		virtual std::string EscapeBlob(const char *s, uint32_t length);
		virtual void FreeResult(DBResult *res);
		virtual int64_t GetLastInsertID();

	protected:
		MYSQL mHandle;
	};

	class MySQLResult : public DBResult
	{
		friend class DatabaseMySQL;

	public:
		MySQLResult(MYSQL_RES* res);
		virtual ~MySQLResult();

		virtual int32_t GetDataInt(const std::string &s);
		virtual int64_t GetDataLong(const std::string &s);
		virtual std::string GetDataString(const std::string &s);
		virtual const char* GetDataStream(const std::string &s, unsigned long &size);
		virtual bool Next();

	protected:
		MYSQL_RES* mHandle;
		MYSQL_ROW mRow;
	};

}

#endif

#endif