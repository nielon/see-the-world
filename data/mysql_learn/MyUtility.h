#ifndef MYTREE_H
#define MYTREE_H 
#include <mysql_driver.h>
#include <mysql_connection.h>

#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>

#include <string>
#include <list>

class Singleton  
{
public:
  static Singleton& Instance()
  {
    static Singleton instance;
    return instance;
  }
private:
  Singleton();
  ~Singleton();
  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);

private:
  sql::Driver *driver;
  sql::Connection *con;
  sql::PreparedStatement *prep_stmt;
  sql::ResultSet *res;

  bool Init();
  bool isInit;

public:
  bool GetResult(const int id, std::list<int>& subids);
};

#endif /* MYTREE_H */
