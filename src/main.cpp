#include <iostream>
#include "life/kernel.h"
#include <life/game_window.h>
#include <life/input_handler.h>
#include <life/texture.h>
#include <life/folder_archive.h>
#include <life/logger.h>

int main()
{
    life::kernel k;

    k.add_service( std::make_unique<life::game_window>( ) );
    k.add_service( std::make_unique<life::input_handler>( ) );

    life::texture t( "font.png",
            std::make_shared<life::folder_archive>( "../assets" ) );

    std::cout << t.load( ) << std::endl;
    //k.run( );

    return 0;
}
