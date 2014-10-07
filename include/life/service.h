#ifndef _LIFE_SERVICE_H_
#define _LIFE_SERVICE_H_

#include "life/gametime.h"
#include <string>

namespace life
{
    class kernel;

    class service
    {
    public:
        service( const std::string& service_name, int priority ) :
            _service_name( service_name ), _priority( priority ) { }
        virtual ~service( ){ }

        virtual const std::string& name( ) const { return _service_name; }

        /// Get the priority of the service for inserting into the kernel
        unsigned int priority( ) const { return _priority; }

        /// Update the service with the current time
        virtual bool update( const life::gametime& ) = 0;

        virtual bool start( ) { return true; }
        virtual void stop( ) { }
        
        void set_owner( kernel* kernel ) { _kernel = kernel; }
        kernel* owner( ) { return _kernel; }
        
    private:

        const std::string _service_name;
        const unsigned int _priority;
        kernel* _kernel;
    };
}

#endif // _LIFE_SERVICE_H_
