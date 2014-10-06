#include <life/game_window.h>
#include <SDL.h>
#include <iostream>

namespace life
{
    ///////////////////////////////////////////////////////////////////////////
    game_window::game_window( ) : service( 1000 ), _window( NULL )
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    game_window::~game_window( )
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    bool game_window::update( const life::gametime& time )
    ///////////////////////////////////////////////////////////////////////////
    {
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    bool game_window::start( kernel * kernel )
    ///////////////////////////////////////////////////////////////////////////
    {
        std::cout << SDL_GetError() << std::endl;
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
            return false;

        _window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                640, 480, SDL_WINDOW_SHOWN );

        if( _window == NULL )
            return false;

        SDL_GetWindowSurface( _window );

        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    void game_window::stop( )
    ///////////////////////////////////////////////////////////////////////////
    {
        SDL_DestroyWindow( _window );
        SDL_Quit( );
    }
}

