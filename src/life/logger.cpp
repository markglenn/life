#include <life/logger.h>
#include <iomanip>

namespace life
{
    inline const char* to_string( log_level level )
    {
        switch( level )
        {
            case log_level::info:
                return "info";
        }

        return "";
    }
    ///////////////////////////////////////////////////////////////////////////
    logger::logger( )
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    logger::~logger( )
    ///////////////////////////////////////////////////////////////////////////
    {
            _os << std::endl;
            fprintf( stderr, "%s", _os.str( ).c_str( ) );
            fflush( stderr );
    }

    ///////////////////////////////////////////////////////////////////////////
    std::ostringstream& logger::get( log_level level )
    ///////////////////////////////////////////////////////////////////////////
    {
        // Current time
        std::time_t t = std::time(nullptr);

        _os << "- "
            << std::put_time( std::localtime( &t ), "%c %Z" )
            << " " << to_string( level ) << ": ";
            
        return _os;
    }
}
