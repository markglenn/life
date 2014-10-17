#include <life.h>
#include <life/game_window.h>
#include <life/logger.h>
#include <SDL2/sdl.h>
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
        {
            LOG(fatal) << "Could not initialize SDL: " << SDL_GetError( );
            return false;
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

        _window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI );

        if( !_window )
        {
            LOG(fatal) << "Could not create window: " << SDL_GetError( );
            return false;
        }

        auto flags = IMG_INIT_PNG | IMG_INIT_JPG;
        if( !( IMG_Init( flags ) & flags ) )
        {
            LOG(fatal) << "Could not initialize image loader: " << IMG_GetError( );
            return false;
        }

        auto context = SDL_GL_CreateContext( _window );
        if( !context )
        {
            LOG(fatal) << "Could not initialize GL Context: " << SDL_GetError( );
            return false;
        }

        _device = std::make_shared<life::device>( this, context );

        LOG(info) << "OpenGL " << glGetString( GL_VERSION );
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    void game_window::stop( )
    ///////////////////////////////////////////////////////////////////////////
    {
        SDL_GL_DeleteContext( _device->context( ) );
        SDL_DestroyWindow( _window );
        SDL_Quit( );
    }
}
