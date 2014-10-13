#include <life/scene.h>
#include <life/game_window.h>
#include <OpenGL/gl.h>

#include <life/logger.h>

namespace life
{
    ///////////////////////////////////////////////////////////////////////////
    int time_per_frame( int frames_per_second, const gametime& gametime )
    ///////////////////////////////////////////////////////////////////////////
    {
        auto time_since_start_of_frame = gametime.time_since_start_of_frame( );

        if ( time_since_start_of_frame > 0 )
            return 1000 / frames_per_second - time_since_start_of_frame * 1000.0;

        return 1000 / frames_per_second;
    }

    ///////////////////////////////////////////////////////////////////////////
    scene::scene( std::shared_ptr<life::device> device ) :
        service{ "Game Scene Provider", 900 },
        _device{ std::move( device ) }
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    scene::~scene( )
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    bool scene::start( )
    ///////////////////////////////////////////////////////////////////////////
    {
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity( );

        glOrtho( 0.0, 640, 480, 0.0, 1.0, -1.0 );

        glClearColor( 1.0, 1.0, 1.0, 0 );
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    void scene::stop( )
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    bool scene::update( const life::gametime& gametime )
    ///////////////////////////////////////////////////////////////////////////
    {
        SDL_GL_SwapWindow( _device->window( )->window( ) );

        SDL_Delay( time_per_frame( 30, gametime ) );
        LOG(info) << 1.0 / (gametime.time_since_start_of_frame() + 0.001);

        //Clear color buffer
        glClear( GL_COLOR_BUFFER_BIT );

        //Reset modelview matrix
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity( );

        return true;
    }
}
