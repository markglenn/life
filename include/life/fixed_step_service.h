#ifndef _LIFE_FIXED_STEP_SERVICE_H_
#define _LIFE_FIXED_STEP_SERVICE_H_

#include <life/service.h>

namespace life
{
    class fixed_step_service : public service
    {
    public:
        fixed_step_service( int frames_per_second );
        virtual ~fixed_step_service( ) { }

        virtual bool update( const life::gametime& );

    private:
        const int _frames_per_second;

    };
}

#endif // _LIFE_FIXED_STEP_SERVICE_H_
