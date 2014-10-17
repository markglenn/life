#ifndef _LIFE_SHADER_H_
#define _LIFE_SHADER_H_

#include <life.h>
#include <life/resource.h>
#include <life/archive.h>
#include <memory>

namespace life
{
    enum class shader_type
    {
        VERTEX_SHADER,
        FRAGMENT_SHADER
    };

    class shader : public resource
    {
    public:
        shader( const std::weak_ptr<life::archive> archive, const std::string filename, const shader_type& type );
        virtual ~shader( );

        virtual bool load( );
        virtual bool unload( );

        const GLuint shader_id( ) const { return _shader_id; }

    private:
        const std::weak_ptr<life::archive> _archive;
        const std::string _filename;
        GLuint _shader_id;
        const shader_type _type;
    };
}

#endif // _LIFE_SHADER_H_
