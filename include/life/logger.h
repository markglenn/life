#ifndef _LIFE_LOGGER_H_
#define _LIFE_LOGGER_H_

#include <sstream>

#ifdef DEBUG
    #define LOG(level) \
        ::life::logger().get(life::log_level::level) \
        << __FILE__ << ":" << __LINE__ << " - "
#else
    #define LOG(level) \
        ::life::logger().get(life::log_level::level)
#endif

namespace life
{
    enum class log_level
    {
        debug,
        info,
        warn,
        error,
        fatal
    };

    // Preferred log method:
    //
    // log(error) << "This is an error";
    //
    // To get:
    //
    // 2014-10-09 13:01:12 - error - src/life/texture.cpp:12 - This is an error
    class logger
    {
    public:
        logger( );
        virtual ~logger( );

        std::ostringstream& get( log_level level = log_level::info );

    protected:
        std::ostringstream _os;

    private:
        // Disable copy constructor
        logger( const logger& );
        logger& operator=( const logger& );
    };
}

#endif // _LIFE_LOGGER_H_
