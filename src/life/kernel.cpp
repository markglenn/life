#include "life/kernel.h"

#include <memory>

namespace life
{
    //////////////////////////////////////////////////////////////////////////
    kernel::kernel( )
    //////////////////////////////////////////////////////////////////////////
    {

    }

    //////////////////////////////////////////////////////////////////////////
    kernel::~kernel( )
    //////////////////////////////////////////////////////////////////////////
    {
        for( auto service : _services )
            delete service;
    }

    //////////////////////////////////////////////////////////////////////////
    bool kernel::add_service( service* service )
    //////////////////////////////////////////////////////////////////////////
    {
        if (!service->start( ) )
            return false;

        int priority = service->priority( );

        // Find where to put the service
        auto pos = std::find_if(
            _services.begin(),
            _services.end(),
            [priority]( auto s ) -> bool { return s->priority() > priority; }
        );

        _services.insert(pos, service);

        return true;
    }
}
