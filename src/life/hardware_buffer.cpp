#include <life.h>
#include <life/hardware_buffer.h>

namespace life
{
    ////////////////////////////////////////////////////////////////////////////
    inline const GLenum convert( const buffer_usage& usage )
    ////////////////////////////////////////////////////////////////////////////
    {
        static GLenum const buffer[] = {
            GL_STATIC_DRAW, GL_DYNAMIC_DRAW, GL_STREAM_DRAW
        };

        return buffer[ static_cast<int>( usage ) ];
    }

    ////////////////////////////////////////////////////////////////////////////
    inline const GLenum convert( const element_type& type )
    ////////////////////////////////////////////////////////////////////////////
    {
        static GLenum const buffer[] = {
            GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT,
            GL_INT, GL_UNSIGNED_INT, GL_FLOAT, GL_DOUBLE
        };

        return buffer[ static_cast<int>( type ) ];
    }
    ////////////////////////////////////////////////////////////////////////////
    hardware_buffer::hardware_buffer( GLuint buffer, buffer_usage usage ) :
        _buffer{ buffer }, _usage{ usage }
    ////////////////////////////////////////////////////////////////////////////
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    hardware_buffer::~hardware_buffer( )
    ////////////////////////////////////////////////////////////////////////////
    {
        glDeleteBuffers( 1, &_buffer );
        check_gl_error( );
    }

    ////////////////////////////////////////////////////////////////////////////
    bool hardware_buffer::write( const void* buffer, std::size_t stride, int count )
    ////////////////////////////////////////////////////////////////////////////
    {
        glBindBuffer( GL_ARRAY_BUFFER, _buffer );
        glBufferData( GL_ARRAY_BUFFER, stride * count, buffer, convert( _usage ) );

        return check_gl_error( );
    }

    ////////////////////////////////////////////////////////////////////////////
    bool hardware_buffer::attributes( unsigned int index, const unsigned int size,
            const element_type& type, std::size_t stride, bool divisor )
    ////////////////////////////////////////////////////////////////////////////
    {
        glEnableVertexAttribArray( index );
        glVertexAttribPointer( index, size, convert( type ), GL_FALSE, stride, 0 );

        if( divisor )
            glVertexAttribDivisor( index, 1 );

        return check_gl_error( );
    }
}
