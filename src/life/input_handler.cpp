#include <life/kernel.h>
#include <life/input_handler.h>
#include <SDL.h>

namespace life
{
    ///////////////////////////////////////////////////////////////////////////
    bool input_handler::update( const life::gametime& )
    ///////////////////////////////////////////////////////////////////////////
    {
        SDL_Event e;

        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
                owner()->stop( );
        }

        return true;
    }
}
