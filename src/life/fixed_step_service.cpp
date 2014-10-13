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
        int delay_time = 1000 / _frames_per_second;

        auto time_since_start_of_frame = time.time_since_start_of_frame( );

        if ( time_since_start_of_frame > 0 )
            delay_time -= static_cast<int>( time_since_start_of_frame * 1000 );

        if (delay_time > 0 )
            SDL_Delay( delay_time );

        auto frame_time = 1.0 / time.time_since_start_of_frame( );

        LOG(info) << frame_time;

        return true;
    }
}
