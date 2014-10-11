#include <life/game_window.h>
#include <life/logger.h>
#include <SDL.h>
#include <SDL_image.h>
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
        {
            LOG(fatal) << "Could not create window: " << SDL_GetError( );
            return false;
        }

        auto renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED );
        if ( nullptr == renderer )
        {
            LOG(fatal) << "Could not create renderer: " << SDL_GetError( );
            return false;
        }

        auto flags = IMG_INIT_PNG || IMG_INIT_JPG;
        if( !( IMG_Init( flags ) & flags ) )
        {
            LOG(fatal) << "Could not initialize image loader: " << IMG_GetError( );
            return false;
        }

        _device = std::make_shared<life::device>( this, renderer );

        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    void game_window::stop( )
    ///////////////////////////////////////////////////////////////////////////
    {
        SDL_DestroyRenderer( _device->renderer( ) );
        SDL_DestroyWindow( _window );
        SDL_Quit( );
    }
}

