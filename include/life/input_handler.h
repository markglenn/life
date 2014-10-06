#ifndef _LIFE_INPUT_HANDLER_H_
#define _LIFE_INPUT_HANDLER_H_

#include <life/service.h>

namespace life
{
    class input_handler : public service
    {
    public:
        input_handler( ) : service( 1000 ) {}
        virtual ~input_handler( ){ }

        virtual std::string name( ) const
        {
            return "Input Handler";
        }

        /// Update the service with the current time
        virtual bool update( const life::gametime& );

        virtual bool start( kernel* );
        virtual void stop( ) { }

    private:

        kernel* _kernel;
    };
}
#endif // _LIFE_INPUT_HANDLER_H_
