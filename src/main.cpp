#include <iostream>
#include "life/kernel.h"
#include <life/game_window.h>

int main()
{
    life::kernel k;
    life::gametime gametime;
    life::game_window window;

    std::cout << window.start( ) << std::endl;

    return 0;
}
