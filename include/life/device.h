#ifndef _LIFE_DEVICE_H_
#define _LIFE_DEVICE_H_

#include <SDL.h>

namespace life
{
    class game_window;
    class device
    {
    public:
        device( game_window* window, SDL_Renderer* renderer, SDL_GLContext context );
        virtual ~device( );
        
        auto renderer( ) const { return _renderer; }
        auto context( ) const { return _context; }
        auto window( ) const { return _window; }

    private:
        game_window* _window;
        SDL_Renderer* _renderer;
        SDL_GLContext _context;
    };
}

#endif // _LIFE_DEVICE_H_
