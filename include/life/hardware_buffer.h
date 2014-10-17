#ifndef _LIFE_HARDWARE_BUFFER_H_
#define _LIFE_HARDWARE_BUFFER_H_

#include <cstddef>
#include <life.h>

namespace life
{
    enum class buffer_usage
    {
        STATIC_DRAW,
        DYNAMIC_DRAW,
        STREAM_DRAW
    };

    enum class element_type
    {
        BYTE,
        UNSIGNED_BYTE,
        SHORT,
        UNSIGNED_SHORT,
        INT,
        UNSIGNED_INT,
        FLOAT,
        DOUBLE
    };

    class hardware_buffer
    {
    public:
        hardware_buffer( GLuint buffer_object, buffer_usage usage );
        virtual ~hardware_buffer( );

        bool write( const void* buffer, std::size_t stride, int count );
        bool attributes( unsigned int index, const unsigned int size, const element_type& type,
                std::size_t stride, bool divisor = false );

        const GLuint& buffer( ) const { return _buffer; }
        const buffer_usage& usage( ) const { return _usage; }

    private:
        const GLuint _buffer;
        const buffer_usage _usage;
    };
}

#endif // _LIFE_HARDWARE_BUFFER_H_
