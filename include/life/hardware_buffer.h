#ifndef _LIFE_HARDWARE_BUFFER_H_
#define _LIFE_HARDWARE_BUFFER_H_

#include <cstddef>
#include <OpenGL/gl.h>

namespace life
{
    enum class buffer_usage
    {
        static_draw,
        dynamic_draw,
        stream_draw
    };

    class hardware_buffer
    {
    public:
        hardware_buffer( GLuint buffer_object, buffer_usage usage );
        virtual ~hardware_buffer( );

        bool write( const void* buffer, std::size_t stride, int count );
        

        const GLuint& buffer( ) const { return _buffer; }
        const buffer_usage& usage( ) const { return _usage; }

    private:
        const GLuint _buffer;
        const buffer_usage _usage;
    };
}

#endif // _LIFE_HARDWARE_BUFFER_H_
