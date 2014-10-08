#include <life/game_window.h>
#include <SDL.h>
#include <iostream>

namespace life
{
    ///////////////////////////////////////////////////////////////////////////
    game_window::game_window( )
        : service{ "Game Window", 1000 }, _window{ nullptr }
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
    bool game_window::start( )
    ///////////////////////////////////////////////////////////////////////////
    {
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
            return false;

        _window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI );

        if( nullptr == _window )
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

