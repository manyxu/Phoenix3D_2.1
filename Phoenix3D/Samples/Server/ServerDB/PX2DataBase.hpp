// PX2DataBase.hpp

#ifndef PX2DATABASE_HPP
#define PX2DATABASE_HPP

#include "PX2Singleton_NeedNew.hpp"
#include "PX2Mutex.hpp"

namespace PX2
{

	typedef std::map<const std::string, uint32_t> ListNames_t;

	enum DBParam
	{
		DBPARAM_MULTIINSERT = 1
	};

	class DBResult;

	class DataBase : public Singleton<DataBase>
	{
	public:
		DataBase();
		virtual ~DataBase();

		virtual bool Connect(const std::string &mysql_ip,
			const std::string &mysql_user, const std::string &mysql_passwd, 
			const std::string &mysql_db, int mysql_port);

		bool IsConnected() const;

		virtual bool GetParam(DBParam param);

	protected:
		friend class DBTransaction;

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
		virtual std::string GetStringComparer();
		virtual std::string GetUpdateLimiter();

	protected:
		DBResult* VerifyResult(DBResult* result);

		bool mIsConnected;
	};

#define PX2_DB DataBase::GetSingleton()

	class DBResult
	{
	public:
		virtual int32_t GetDataInt(const std::string &s);
		virtual int64_t GetDataLong(const std::string &s);
		virtual std::string GetDataString(const std::string &s);
		virtual const char* GetDataStream(const std::string &s, unsigned long &size);
		virtual bool Next();

		ListNames_t GetListNames() const;

	protected:
		DBResult();
		virtual ~DBResult();

		ListNames_t mListNames;
	};

	class DBQueryStream : public std::stringstream
	{
		friend class Database;

	public:
		DBQueryStream();
		virtual ~DBQueryStream();

	protected:
		static Mutex sDataBaseLock;
	};

	class DBInsert
	{
	public:
		DBInsert(DataBase* db);
		~DBInsert();

		void SetQuery(const std::string& query);
		bool AddRow(const std::string& row);
		bool AddRow(std::stringstream& row);

		bool Execute();

		uint64_t GetInsertID();

	protected:
		DBInsert();

		DataBase* mDataBase;
		bool mIsMultiLine;
		uint32_t mNumRows;
		std::string mQuery;
		std::string mBuffer;
	};

	class DBTransaction
	{
	public:
		DBTransaction(DataBase* database);
		~DBTransaction();

		bool Begin();
		bool Commit();

	private:
		DataBase* mDatabase;

		enum TransactionState
		{
			STATE_NO_START,
			STATE_START,
			STEATE_COMMIT
		};
		TransactionState mState;
	};

#include "PX2DataBase.inl"

}

#endif
