#include "life/gametime.h"

using namespace std::chrono;

constexpr double microseconds_in_seconds = 1000.0 * 1000.0;

namespace life
{
    //////////////////////////////////////////////////////////////////////////
    gametime::gametime( ) :
        _start_time( high_resolution_clock::now( ) ),
        _current_time( _start_time ),
        _total_time( 0 ), _current_step( 0 )
    //////////////////////////////////////////////////////////////////////////
    {
    }

    //////////////////////////////////////////////////////////////////////////
    void gametime::update( )
    //////////////////////////////////////////////////////////////////////////
    {
        double previous_time = _total_time;

        // Update the current time
        _current_time = high_resolution_clock::now( );

        _total_time = duration_cast<microseconds>( _current_time - _start_time ).count( ) /
            microseconds_in_seconds;

        _current_step = _total_time - previous_time;
    }
}