#ifndef _LIFE_GAME_WINDOW_SERVICE_H_
#define _LIFE_GAME_WINDOW_SERVICE_H_

#include <string>
#include "service.h"

class SDL_Window;

namespace life
{
    class game_window : public service
    {
    public:
        game_window( );
        virtual ~game_window( );

        virtual std::string name( ) const
        {
            return "Game Window";
        }

        /// Update the service with the current time
        virtual bool update( const life::gametime& );
        virtual bool start( );
        virtual void stop( );

    private:

        SDL_Window* _window;
    };
}

#endif // _LIFE_GAME_WINDOW_SERVICE_H_