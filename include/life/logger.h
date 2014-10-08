#ifndef _LIFE_LOGGER_H_
#define _LIFE_LOGGER_H_

#include <sstream>

namespace life
{
    enum class log_level
    {
        info
    };

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
