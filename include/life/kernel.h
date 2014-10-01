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

        std::list<service*>::const_iterator cbegin( ) { return _services.cbegin(); }
        std::list<service*>::const_iterator cend( ) { return _services.cend(); }

    private:
        std::list<service*> _services;
    };
}

#endif // _LIFE_KERNEL_H_
