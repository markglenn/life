#include "life/kernel.h"

#include <memory>
#include <iostream>

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
        for( auto& service : _services )
            service->stop( );
    }

    //////////////////////////////////////////////////////////////////////////
    bool kernel::add_service( std::unique_ptr<service> service )
    //////////////////////////////////////////////////////////////////////////
    {
        service->set_owner( this );
        if (!service->start( ) )
            return false;

        int priority = service->priority( );

        // Find where to put the service
        auto pos = std::find_if(
            _services.begin(),
            _services.end(),
            [priority]( auto& s ) -> bool { return s->priority() > priority; }
        );

        _services.insert(pos, std::move( service ) );

        return true;

    }

    //////////////////////////////////////////////////////////////////////////
    bool kernel::add_service( service* service )
    //////////////////////////////////////////////////////////////////////////
    {
        return add_service( std::unique_ptr<life::service>( service ) );
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
                    ( *i )->stop( );
                    i = _services.erase( i );
                }
            }

            // Check if any services are still running
            if ( _is_running )
                _is_running = _services.size( ) > 0;
        }
    }
}
