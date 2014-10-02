#ifndef _LIFE_SERVICE_H_
#define _LIFE_SERVICE_H_

#include "life/gametime.h"

namespace life
{
    class service
    {
    public:
        service( int priority ) : _priority( priority ) {}
        virtual ~service( ){ }

        virtual std::string name( ) const = 0;

        /// Get the priority of the service for inserting into the kernel
        unsigned int priority( ) const { return _priority; }

        /// Update the service with the current time
        virtual bool update( const life::gametime& ) = 0;
        
    private:
        const unsigned int _priority;
    };
}

#endif // _LIFE_SERVICE_H_
