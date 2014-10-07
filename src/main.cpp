#include <iostream>
#include "life/kernel.h"
#include <life/game_window.h>
#include <life/input_handler.h>

int main()
{
    life::kernel k;

    k.add_service( std::make_unique<life::game_window>( ) );
    k.add_service( std::make_unique<life::input_handler>( ) );

    k.run( );

    return 0;
}
