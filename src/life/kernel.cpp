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
        // Find where to put the service
        auto pos = std::find_if(
            _services.begin(),
            _services.end(),
            [=]( auto s ) -> bool { return s->get_priority() > service->get_priority(); }
        );

        _services.insert(pos, service);

        return false;
    }
}
