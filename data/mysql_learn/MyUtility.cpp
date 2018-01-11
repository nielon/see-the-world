#include "MyUtility.h"
#include <iostream>
using namespace std;

Singleton::Singleton()
{
  isInit = false;
}

bool Singleton::Init()
{
try {

  driver = sql::mysql::get_mysql_driver_instance();
  //con = driver->connect("192.168.195.1", "common_user", "common_user");
  con = driver->connect("tcp://192.168.195.1:3307/testdb", "root", "Debian.lyw");
  while (! con->isValid())
  {
    sleep(2);
    con->reconnect();
  }
  //con->setSchema("testdb");
  // tasks
  const string prep_sql = "select * from zhl_knowledge where parent_id = ?";
  prep_stmt = con->prepareStatement(prep_sql);
  isInit = true;
  return true;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line"
    << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << ")" << endl;
  return false;
}
}

bool Singleton::GetResult(const int id, std::list<int>& subids)
{
  if (isInit == false)
    Init();
try {

  prep_stmt->setInt(1, id);
  prep_stmt->execute();
   
  res = prep_stmt->executeQuery();
  while (res->next())
  {
    subids.push_back(res->getInt(1));
    cout << "id = " << res->getInt(1);
    cout << ", name = " << res->getString("name") << endl;
  }
  return true;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line"
    << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << ")" << endl;
}
  cout << endl;
  return false;
}

Singleton::~Singleton()
{
  delete prep_stmt;
  delete res;
  delete con;
}
