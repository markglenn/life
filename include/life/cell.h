#ifndef _LIFE_CELL_H_
#define _LIFE_CELL_H_

#include <life.h>
#include <life/resource.h>
#include <life/shader.h>

namespace life
{
    class cell : public resource
    {
    public:
        cell( std::shared_ptr<archive> assets );
        virtual ~cell( );

        virtual bool load( );
        virtual bool unload( );

    private:

        enum buffer_position
        {
            VERTEX_BUFFER_POSITION,
            INDEX_BUFFER_POSITION
        };

        GLuint _vertex_array_object;
        GLuint _buffers[2];

        shader _vertex_shader;
        shader _fragment_shader;
    };
}

#endif // _LIFE_CELL_H_
