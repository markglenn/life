#ifndef _LIFE_DEVICE_H_
#define _LIFE_DEVICE_H_

#include <SDL.h>

namespace life
{
    class device
    {
    public:
        device( SDL_Renderer* renderer );
        virtual ~device( );
        
        SDL_Renderer* renderer( ) const { return _renderer; }

    private:
        SDL_Renderer* _renderer;
    };
}

#endif // _LIFE_DEVICE_H_
