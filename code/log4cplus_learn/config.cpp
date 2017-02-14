/*
 *标准使用，严格实现步骤1-6。
　*/
#include <unistd.h>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

static Logger logger = Logger::getInstance("log");
void printDebug()
{
    LOG4CPLUS_TRACE_METHOD(logger, "::printDebug()");
    LOG4CPLUS_DEBUG(logger, "This is a DEBUG message");
    LOG4CPLUS_INFO(logger, "This is a INFO message");
    LOG4CPLUS_WARN(logger, "This is a WARN message");
    LOG4CPLUS_ERROR(logger, "This is a ERROR message");
    LOG4CPLUS_FATAL(logger, "This is a FATAL message");
}
int main()
{
  Logger root = Logger::getRoot();
  PropertyConfigurator::doConfigure("urconfig.properties");
  printDebug();

  return 0;
}

