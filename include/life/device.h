#ifndef _LIFE_DEVICE_H_
#define _LIFE_DEVICE_H_

#include <SDL.h>

namespace life
{
    class game_window;
    class device
    {
    public:
        device( game_window* window, SDL_Renderer* renderer );
        virtual ~device( );
        
        SDL_Renderer* renderer( ) const { return _renderer; }
        game_window* window( ) const { return _window; }

    private:
        game_window* _window;
        SDL_Renderer* _renderer;
    };
}

#endif // _LIFE_DEVICE_H_
