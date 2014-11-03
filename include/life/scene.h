#ifndef _LIFE_SCENE_H_
#define _LIFE_SCENE_H_

#include <life/device.h>
#include <life/service.h>
#include <life/archive.h>
#include <life/cell.h>

namespace life
{
    class scene : public service
    {
    public:
        scene( std::shared_ptr<life::device> device, std::shared_ptr<life::archive> assets );
        virtual ~scene( );

        /// Update the service with the current time
        virtual bool update( const life::gametime& );

        virtual bool start( );
        virtual void stop( );

    protected:
        const std::shared_ptr<life::device> _device;
        const std::shared_ptr<life::archive> _assets;

        life::cell _cell;
    };
}

#endif // _LIFE_SCENE_H_
