#include <mysql_driver.h>
#include <mysql_connection.h>

#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>

#include <iostream>
using namespace std;
int main(void)
{
try {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::PreparedStatement *prep_stmt;
  sql::ResultSet *res;

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
  stmt = con->createStatement();
  const string drop = "drop table if exists testdb.teacher";
  //const string choice = "use testdb";
  const string create = "create table teacher(id int, name char(10))";
  const string insert = "insert into teacher(id,name) values(1, 'lily')";
  const string insert2 = "insert into teacher(id,name) values(2, 'liliqin')";
  const string query = "select * from teacher";
  stmt->execute(drop);
  //stmt->execute(choice);
  stmt->execute(create);
  stmt->execute(insert);

  const string prep_sql = "insert into teacher(id,name) values(?, ?)";
  prep_stmt = con->prepareStatement(prep_sql);
  prep_stmt->setInt(1, 11);
  prep_stmt->setString(2, "wangyiheng");
  prep_stmt->execute();

  prep_stmt->setInt(1, 12);
  prep_stmt->setString(2, "anlu");
  prep_stmt->execute();
   
  res = stmt->executeQuery(query);
  while (res->next())
  {
    cout << "id = " << res->getInt(1);
    cout << ", name = " << res->getString("name") << endl;
  }

  delete prep_stmt;
  delete res;
  delete stmt;
  delete con;
} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line"
    << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << ")" << endl;
}
  cout << endl;
  return EXIT_SUCCESS;
}
