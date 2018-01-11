/*
 *标准使用，严格实现步骤1-6。
　*/
#include <unistd.h>
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/helpers/property.h>
#include <log4cplus/loggingmacros.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

int main()
{
    /* step 1: Instantiate an appender object */
    SharedObjectPtr<Appender> _append (new FileAppender("log/test.log"));
    _append->setName("append for test");
    SharedObjectPtr<Appender> _append_gen (new FileAppender("log/gen.log"));
    _append_gen->setName("append for gen");
    SharedObjectPtr<Appender> _append_consume (new FileAppender("log/consume.log"));
    _append_consume->setName("append for consume");

    /* step 2: Instantiate a layout object */
    std::string pattern = "%D{%Y/%m/%d/ %H:%M:%S}  - %m [%l]%n";
    std::auto_ptr<Layout> _layout(new PatternLayout(pattern));
    log4cplus::helpers::Properties properties;
    properties.setProperty("DateFormat", "%Y/%m/%d/ %H:%M:%S");
    properties.setProperty("Use_gmtime", "false");
    std::auto_ptr<Layout> _layout_ttcc(new TTCCLayout(properties));

    /* step 3: Attach the layout object to the appender */
    _append->setLayout( _layout);
    _append_gen->setLayout( _layout_ttcc);
    //_append_consume->setLayout( _layout_ttcc);

    /* step 4: Instantiate a logger object */
    Logger _logger= Logger::getInstance("test");
    Logger _logger_gen= Logger::getInstance("test.gen");
    Logger _logger_consume= Logger::getInstance("test.consume");

    /* step 5: Attach the appender object to the logger  */
    _logger.addAppender(_append);
    _logger_gen.addAppender(_append_gen);
    _logger_consume.addAppender(_append_consume);

    /* step 6: Set a priority for the logger  */
    _logger.setLogLevel(ALL_LOG_LEVEL);

    /* log activity */
    LOG4CPLUS_DEBUG(_logger_gen, "This is A GEN log message...");
    sleep(1);
    LOG4CPLUS_DEBUG(_logger_consume, "This is A CONSUME log message...");
    return 0;
}
