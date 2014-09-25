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

    private:
        std::list< std::unique_ptr<service> > _services;
    };
}

#endif // _LIFE_KERNEL_H_
