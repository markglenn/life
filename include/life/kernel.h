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
        int service_count( ) const { return _services.size(); }

        /// Add a service to the running kernel
        bool add_service( service* );
        bool add_service( std::unique_ptr<service> );

        /// Stop all services in the kernel
        void stop( ) { _is_running = false; }

        auto cbegin( ) const { return _services.cbegin(); }
        auto cend( ) const { return _services.cend(); }

        auto begin( ) { return _services.begin(); }
        auto end( ) { return _services.end(); }

        void run( );

    private:
        std::list< std::unique_ptr<service> > _services;
        bool _is_running;
    };
}

#endif // _LIFE_KERNEL_H_
