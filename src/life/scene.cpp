#include <life/scene.h>
#include <life/game_window.h>
#include <OpenGL/gl.h>

#include <life/logger.h>
#include <life/hardware_buffer.h>

namespace life
{

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
        GLuint buffer;
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity( );

        glOrtho( 0.0, 640, 480, 0.0, 1.0, -1.0 );

        glClearColor( 1.0, 1.0, 1.0, 0 );
        glGenBuffers(1, &buffer );
        auto b = hardware_buffer{ buffer, buffer_usage::static_draw };

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


        //Clear color buffer
        glClear( GL_COLOR_BUFFER_BIT );

        //Reset modelview matrix
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity( );

        return true;
    }
}
