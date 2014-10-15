#ifndef _LIFE_OPENGL_ERROR_HANDLER_H_
#define _LIFE_OPENGL_ERROR_HANDLER_H_

#define check_gl_error( ) life::_check_gl_error( __FILE__,__LINE__ )

namespace life
{
    // Log the opengl errors
    bool _check_gl_error( const char *file, int line );
}

#endif // _LIFE_OPENGL_ERROR_HANDLER_H_
