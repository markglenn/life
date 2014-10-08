#ifndef _LIFE_INPUT_HANDLER_H_
#define _LIFE_INPUT_HANDLER_H_

#include <life/service.h>

namespace life
{
    class input_handler : public service
    {
    public:
        input_handler( ) : service{ "Input Handler", 1000 } {}
        virtual ~input_handler( ){ }

        /// Update the service with the current time
        virtual bool update( const life::gametime& );
    };
}
#endif // _LIFE_INPUT_HANDLER_H_
