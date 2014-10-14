#ifndef _LIFE_RESOURCE_H_
#define _LIFE_RESOURCE_H_

#include <string>
#include <memory>
#include <life/archive.h>

namespace life
{
    class resource
    {
    public:
        resource( ) { }
        virtual ~resource( ) { }

        virtual bool load( ) = 0;
        virtual bool unload( ) = 0;
    };
}

#endif // _LIFE_RESOURCE_H_
