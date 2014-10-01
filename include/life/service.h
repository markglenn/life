#ifndef _LIFE_SERVICE_H_
#define _LIFE_SERVICE_H_

namespace life
{
    class service
    {
    public:
        service( int priority ) : _priority( priority ) {}
        virtual ~service( ){ }

        /// Get the priority of the service for inserting into the kernel
        virtual int get_priority( ) const { return _priority; }

    private:
        int _priority;
    };
}

#endif // _LIFE_SERVICE_H_
