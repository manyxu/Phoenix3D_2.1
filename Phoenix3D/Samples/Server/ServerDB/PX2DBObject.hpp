// PX2DBObject.hpp

#ifndef PX2DBOBJECT_HPP
#define PX2DBOBJECT_HPP

#include "PX2NetPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Mutex.hpp"
#include "mysql.h"

namespace PX2Server
{

	class DBObject
	{
	public:
		DBObject();
		~DBObject();

		bool Connect(const std::string &mysql_ip, const std::string &mysql_user,
			const std::string &mysql_passwd, const std::string &mysql_db,
			int mysql_port);

		bool Execute(const std::string &sqlStr);
		bool Fetch();
		void EndFetch();

		bool StoreResult(bool storeType = true);

		int GetAffectedRow();

		DBObject& operator >> (char &nVal);
		DBObject& operator >> (short &nVal);
		DBObject& operator >> (long &nVal);
		DBObject& operator >> (int &nVal);
		DBObject& operator >> (int64_t &i64Val);
		DBObject& operator >> (std::string &strVal);
		void GetBinaryData(char* buf, std::size_t &bufsize);

	protected:
		MYSQL mMySQL;
		MYSQL_RES *mMySQL_Result;
		MYSQL_ROW mMySQL_Row;
		unsigned long *m_plength;
		bool mIsInited;
		int m_effectrow;
		int m_ncolumnno;
		std::vector<unsigned int> m_vfiledlength;
		
		std::string mMySQL_IP;
		std::string mMySQL_User;
		std::string mMySQL_Password;
		std::string mMySQL_DB;
		int mMySQL_Port;
	};

	class DBPool : public PX2::Singleton<DBPool>
	{
	public:
		DBPool();
		~DBPool();

		DBObject* GetDB(const std::string &mysql_ip, const std::string &mysql_user, 
			const std::string &mysql_passwd, const std::string& mysql_db, int mysql_port);

		bool ConnectAllDB(const std::vector<int> &threadIDs, const std::string& mysql_ip,
			const std::string& mysql_user, const std::string& mysql_passwd,
			const std::string& mysql_db, int mysql_port);
	public:
		void KeepLive(double appTime);

	private:
		PX2::Mutex mMutex;
		std::map<int, DBObject*> mPool;
	};


}

#endif