#ifndef _LIFE_HARDWARE_BUFFER_H_
#define _LIFE_HARDWARE_BUFFER_H_

#include <cstddef>
#include <OpenGL/gl.h>

namespace life
{
    class hardware_buffer
    {
    public:
        hardware_buffer( GLuint buffer_object );
        virtual ~hardware_buffer( );

        bool write( const void* buffer, std::size_t size, int count );

    private:
        GLuint _buffer_object;
    };
}

#endif // _LIFE_HARDWARE_BUFFER_H_
