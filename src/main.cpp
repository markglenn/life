#include <iostream>
#include "life/kernel.h"
#include "life/gametime.h"
#include "life/folder_archive.h"

int main()
{
    life::kernel k;
    life::gametime gametime;

    gametime.update();
    std::cout << gametime.current_step() << std::endl;

    gametime.update();
    std::cout << gametime.current_step() << std::endl;

    gametime.update();
    std::cout << gametime.current_step() << std::endl;

    gametime.update();
    std::cout << gametime.current_step() << std::endl;
    return 0;
}
