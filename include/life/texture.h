#ifndef _LIFE_TEXTURE_H_
#define _LIFE_TEXTURE_H_

#include <life/resource.h>

namespace life
{
    class texture : public resource
    {
    public:
        texture( std::string path, std::shared_ptr<life::archive> archive );
        virtual ~texture( );

        virtual bool load( );
        virtual bool unload( );
    };
}

#endif // _LIFE_TEXTURE_H_
