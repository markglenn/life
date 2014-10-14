#include <SDL.h>
#include <life/logger.h>
#include <life/fixed_step_service.h>

namespace life
{
    ////////////////////////////////////////////////////////////////////////////
    fixed_step_service::fixed_step_service( int frames_per_second ) :
        service{ "Fixed step service", 10000 },
        _frames_per_second{ frames_per_second }
    ////////////////////////////////////////////////////////////////////////////
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    bool fixed_step_service::update( const life::gametime& time )
    ////////////////////////////////////////////////////////////////////////////
    {
        // Standard delay time if application takes no time at all
        int delay_time = 1000 / _frames_per_second;

        auto time_since_start_of_frame = time.time_since_start_of_frame( );

        // Adjust delay time for how much time has been spent on the frame so far
        if ( time_since_start_of_frame > 0 )
            delay_time -= static_cast<int>( time_since_start_of_frame * 1000 );

        // If we have time to kill, sleep this thread
        if (delay_time > 0 )
        {
            LOG(info) << delay_time;
            SDL_Delay( delay_time );
        }

        return true;
    }
}
