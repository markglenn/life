#include "life/kernel.h"

#include <memory>

namespace life
{
    //////////////////////////////////////////////////////////////////////////
    kernel::kernel( ) : _is_running( true )
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
        if (!service->start( this ) )
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

    //////////////////////////////////////////////////////////////////////////
    void kernel::run( )
    //////////////////////////////////////////////////////////////////////////
    {
        life::gametime gametime;

        while( _is_running )
        {
            for( auto i = _services.cbegin(); i != _services.cend(); )
            {
                // Update the time to the latest time step
                gametime.update( );

                if( ( *i )->update( gametime ) )
                {
                    // The service update is still alive, increment the iterator
                    ++i;
                }
                else
                {
                    // Service stopped, remove it
                    delete *i;
                    i = _services.erase( i );
                }
            }

            // Check if any services are still running
            if ( _is_running )
                _is_running = _services.size( ) > 0;
        }
    }
}
