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
        resource( const std::string path, const std::weak_ptr<life::archive> archive );
        virtual ~resource( );

        virtual bool load( ) = 0;
        virtual bool unload( ) = 0;

    protected:
        const auto& archive( ) const { return _archive; }
        const auto& path( ) const {
            return _path;
        }

    private:
        const std::string _path;
        const std::weak_ptr<life::archive> _archive;
    };
}

#endif // _LIFE_RESOURCE_H_
