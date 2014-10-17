#ifndef _LIFE_DEVICE_H_
#define _LIFE_DEVICE_H_

#include <SDL2/sdl.h>

namespace life
{
    class game_window;
    class device
    {
    public:
        device( game_window* window, SDL_GLContext context );
        virtual ~device( );
        
        auto context( ) const { return _context; }
        auto window( ) const { return _window; }

    private:
        game_window* _window;
        SDL_GLContext _context;
    };
}

#endif // _LIFE_DEVICE_H_
