#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
//uncomment for applications that use vectors
//#include <vector>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

using namespace std;

const string EXAMPLE_HOST = "192.168.195.1:3307";
const string EXAMPLE_USER = "root";
const string EXAMPLE_PASS = "Debian.lyw";
const string EXAMPLE_DB   = "testdb";

int main(int argc, char *argv[])
{
  const string url(argc>=2 ? argv[1] : EXAMPLE_HOST);
  const string user(argc>=3 ? argv[2] : EXAMPLE_USER);
  const string pass(argc>=4 ? argv[3] : EXAMPLE_PASS);
  const string database(argc>=5 ? argv[4] : EXAMPLE_DB);

  cout << "Connect/C++ tutorial framework..." << endl;
  cout << endl;

  try {
    //INSERT TUTORIAL CODE HERE!
  } catch (sql::SQLException &e) {
    /*
     *   MySQL Connector/C++ throws three different exceptions:
     *
     *     - sql::MethodNotImplementedException (derived from sql::SQLException)
     *     - sql::InvalidArgumentException (derived from sql::SQLException)
     *     - sql::SQLException (derived from std::runtime_error)
     */
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    /* what() (derived from std::runtime_error) fetches error message */
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;

    return EXIT_FAILURE;
  }

  cout << "Done." << endl;
  return EXIT_SUCCESS;
}
