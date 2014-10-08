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
        resource( std::string path, std::shared_ptr<life::archive> archive );
        virtual ~resource( );

        virtual bool load( ) = 0;
        virtual bool unload( ) = 0;

    protected:
        const life::archive* archive( ) const;
        const std::string path( ) const;

    private:
        const std::string _path;
        const std::shared_ptr<life::archive> _archive;
    };
}

#endif // _LIFE_RESOURCE_H_
