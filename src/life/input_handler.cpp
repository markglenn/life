#include <life/kernel.h>
#include <life/input_handler.h>
#include <SDL.h>

namespace life
{
    ///////////////////////////////////////////////////////////////////////////
    bool input_handler::start( kernel* kernel )
    ///////////////////////////////////////////////////////////////////////////
    {
        _kernel = kernel;
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    bool input_handler::update( const life::gametime& )
    ///////////////////////////////////////////////////////////////////////////
    {
        SDL_Event e;

        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
                _kernel->stop( );
        }

        return true;
    }
}
