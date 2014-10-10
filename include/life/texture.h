#ifndef _LIFE_TEXTURE_H_
#define _LIFE_TEXTURE_H_

#include <memory>

#include <life/resource.h>
#include <life/device.h>

namespace life
{
    class texture : public resource
    {
    public:
        texture( std::shared_ptr<life::device> device, std::string path, std::shared_ptr<life::archive> archive );
        virtual ~texture( );

        virtual bool load( );
        virtual bool unload( );

    private:

        std::shared_ptr<life::device> _device;
    };
}

#endif // _LIFE_TEXTURE_H_
