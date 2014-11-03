#include <life.h>
#include <life/scene.h>
#include <life/game_window.h>

#include <life/logger.h>

namespace life
{

    ///////////////////////////////////////////////////////////////////////////
    scene::scene( std::shared_ptr<life::device> device, std::shared_ptr<life::archive> assets ) :
        service{ "Game Scene Provider", 900 },
        _device{ std::move( device ) },
        _assets{ std::move( assets ) },
        _cell{ _assets }
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
        if ( !_cell.load( ) )
            return false;

        glClearColor( 1.0, 1.0, 1.0, 0 );
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    void scene::stop( )
    ///////////////////////////////////////////////////////////////////////////
    {
        _cell.unload( );
    }

    ///////////////////////////////////////////////////////////////////////////
    bool scene::update( const life::gametime& gametime )
    ///////////////////////////////////////////////////////////////////////////
    {
        glDrawElementsInstanced( GL_TRIANGLE_FAN, 2, GL_UNSIGNED_INT, 0, 1 );

        if ( check_gl_error( ) )
            return false;

        SDL_GL_SwapWindow( _device->window( )->window( ) );

        //Clear color buffer
        glClear( GL_COLOR_BUFFER_BIT );

        //Reset modelview matrix
        //glMatrixMode( GL_MODELVIEW );
        //glLoadIdentity( );

        return true;
    }
}
