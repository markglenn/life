#ifndef _LIFE_CELL_H_
#define _LIFE_CELL_H_

#include <OpenGL/gl.h>

#include <life.h>
#include <life/resource.h>

namespace life
{
    class cell : public resource
    {
    public:
        cell( );
        virtual ~cell( );

        virtual bool load( );
        virtual bool unload( );

    private:

        enum buffer_position
        {
            VERTEX_BUFFER_POSITION,
            INDEX_BUFFER_POSITION
        };

        GLuint _buffers[2];
    };
}

#endif // _LIFE_CELL_H_
