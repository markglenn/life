#ifndef _LIFE_GAMETIME_H_
#define _LIFE_GAMETIME_H_

#include <chrono>

namespace life
{
    class gametime
    {
    public:
        gametime( );

        double total_time( ) const
        {
            return _total_time;
        }

        double current_step( ) const
        {
            return _current_step;
        }

        void update( );

    private:

        std::chrono::high_resolution_clock::time_point _start_time;
        std::chrono::high_resolution_clock::time_point _current_time;
        double _total_time;
        double _current_step;
    };
}

#endif // _LIFE_GAMETIME_H_
