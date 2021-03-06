#ifndef _LIFE_KERNEL_H_
#define _LIFE_KERNEL_H_

#include <list>
#include <memory>

#include "life/service.h"

namespace life
{
    class kernel
    {
    public:
        kernel();
        virtual ~kernel();

        /// Number of services currently in the kernel
        auto service_count( ) const { return _services.size(); }

        /// Add a service to the running kernel
        bool add_service( const std::shared_ptr<service>& );
        bool add_service( service* service )
        {
            return add_service( std::unique_ptr<life::service>( service ) );
        }

        /// Stop all services in the kernel
        void stop( ) { _is_running = false; }

        auto cbegin( ) const { return _services.cbegin(); }
        auto cend( ) const { return _services.cend(); }

        auto begin( ) { return _services.begin(); }
        auto end( ) { return _services.end(); }

        void run( );

    private:
        std::list<std::shared_ptr<service>> _services;
        bool _is_running;
    };
}

#endif // _LIFE_KERNEL_H_
