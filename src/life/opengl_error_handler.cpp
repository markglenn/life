#include <life/opengl_error_handler.h>

#include <OpenGL/gl.h>
#include <life/logger.h>

namespace life
{
    bool _check_gl_error(const char *file, int line)
    {
        auto has_error = false;

        while( auto err = glGetError( ) )
        {
            has_error = true;
            std::string error;

            switch(err)
            {
                case GL_INVALID_OPERATION:              error="INVALID_OPERATION";              break;
                case GL_INVALID_ENUM:                   error="INVALID_ENUM";                   break;
                case GL_INVALID_VALUE:                  error="INVALID_VALUE";                  break;
                case GL_OUT_OF_MEMORY:                  error="OUT_OF_MEMORY";                  break;
                case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
                case GL_STACK_UNDERFLOW:                error="STACK_UNDERFLOW";                break;
                case GL_STACK_OVERFLOW:                 error="STACK_OVERFLOW";                 break;
            }

            logger( ).get( log_level::error ) << file << ":" << line <<
                " - " << "GL_" << error;
        }

        return has_error;
    }
}
