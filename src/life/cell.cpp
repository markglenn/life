#include <life/cell.h>
#include <glm/glm.hpp>

namespace life
{
    ////////////////////////////////////////////////////////////////////////////
    cell::cell( std::shared_ptr<archive> assets ) :
        _vertex_shader{ shader{ assets, "shaders/cell.vert", life::shader_type::VERTEX_SHADER } },
        _fragment_shader{ shader{ assets, "shaders/cell.frag", life::shader_type::FRAGMENT_SHADER } }
    ////////////////////////////////////////////////////////////////////////////
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    cell::~cell( )
    ////////////////////////////////////////////////////////////////////////////
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    bool cell::load( )
    ////////////////////////////////////////////////////////////////////////////
    {
        if( !_vertex_shader.load( ) )
        {
            LOG(error) << "Could not load vertex shader";
            return false;
        }

        if( !_fragment_shader.load( ) )
        {
            LOG(error) << "Could not load fragment shader";
            return false;
        }

        glGenBuffers( 2, _buffers );
        glGenVertexArrays( 1, &_vertex_array_object );

        glBindVertexArray( _vertex_array_object );

        const glm::vec2 positions[] = {
            { 0.0f, 0.0f },
            { 1.0f, 0.0f },
            { 0.0f, 2.0f },
            { 1.0f, 2.0f }
        };

        // 0 - 1
        // | \ *
        // 2 - 3
        const unsigned int indices[] = {
            0, 1, 3, 2
        };

        // Initialize the rectangle positions
        glBindBuffer( GL_ARRAY_BUFFER, _buffers[ VERTEX_BUFFER_POSITION ] );
        glBufferData( GL_ARRAY_BUFFER, sizeof( positions ), positions, GL_STATIC_DRAW );

        glEnableVertexAttribArray( VERTEX_BUFFER_POSITION );

        glVertexAttribPointer( VERTEX_BUFFER_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof( glm::vec2 ), 0 );
        glVertexAttribDivisor( VERTEX_BUFFER_POSITION, 1 );

        // Initialize the index buffer
        glBindBuffer( GL_ARRAY_BUFFER, _buffers[ INDEX_BUFFER_POSITION ] );
        glBufferData( GL_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );

        return !check_gl_error( );
    }

    ////////////////////////////////////////////////////////////////////////////
    bool cell::unload( )
    ////////////////////////////////////////////////////////////////////////////
    {
        glDeleteBuffers( 2, _buffers );

        _vertex_shader.unload( );
        _fragment_shader.unload( );

        return !check_gl_error( );
    }
}
