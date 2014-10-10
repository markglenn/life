#ifndef _LIFE_GAME_WINDOW_SERVICE_H_
#define _LIFE_GAME_WINDOW_SERVICE_H_

#include <string>
#include <memory>
#include "device.h"
#include "service.h"

class SDL_Window;

namespace life
{
    class game_window : public service
    {
    public:
        game_window( );
        virtual ~game_window( );

        /// Update the service with the current time
        virtual bool update( const life::gametime& );
        virtual bool start( );
        virtual void stop( );

        const auto& device( ) const { return _device; }

    private:

        SDL_Window* _window;
        std::shared_ptr<life::device> _device;
    };
}

#endif // _LIFE_GAME_WINDOW_SERVICE_H_
