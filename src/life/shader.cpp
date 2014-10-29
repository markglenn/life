#include <life/shader.h>
#include <iostream>
#include <vector>

using std::ios;

namespace life
{
    ////////////////////////////////////////////////////////////////////////////
    shader::shader(const std::weak_ptr<life::archive> archive,
            const std::string filename, const shader_type& type ) :
        _archive{ std::move( archive ) },
        _filename{ std::move( filename ) },
        _shader_id{ 0 },
        _type{ type }
    ////////////////////////////////////////////////////////////////////////////
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    shader::~shader( )
    ////////////////////////////////////////////////////////////////////////////
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    bool shader::load( )
    ////////////////////////////////////////////////////////////////////////////
    {
        const std::istreambuf_iterator<char> eos;

        if ( auto archive_ptr = _archive.lock( ) )
        {
            auto stream = archive_ptr->open( _filename, ios::in );
            auto source = std::string{ std::istreambuf_iterator<char>(*stream), eos };

            auto source_ptr = source.c_str( );

            _shader_id = glCreateShader( GL_VERTEX_SHADER );
            int length = source.size( );
            glShaderSource( _shader_id, 1, &source_ptr, &length );
            glCompileShader( _shader_id );

            GLint compiled;

            glGetShaderiv(_shader_id, GL_COMPILE_STATUS, &compiled);

            if( !compiled )
            {
                LOG( error ) << "Could not compile";

                char buffer[512];
                glGetShaderInfoLog(_shader_id, 512, NULL,buffer);
                printf("%s",buffer);
            }
        }

        return !check_gl_error( );
    }

    ////////////////////////////////////////////////////////////////////////////
    bool shader::unload( )
    ////////////////////////////////////////////////////////////////////////////
    {
        return true;
    }
}
