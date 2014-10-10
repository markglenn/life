#include <iostream>
#include "life/kernel.h"
#include <life/game_window.h>
#include <life/input_handler.h>
#include <life/texture.h>
#include <life/folder_archive.h>
#include <life/logger.h>

int main()
{
    LOG(info) << "Started Life";
    life::kernel k;

    k.add_service( std::make_unique<life::game_window>( ) );
    k.add_service( std::make_unique<life::input_handler>( ) );

    auto assets = std::make_shared<life::folder_archive>( "../assets" );
    life::texture font( "font.png", assets );

    if ( font.load( ) )
        LOG( info ) << "Font file loaded successfully";

    //k.run( );

    font.unload( );
    LOG(info) << "Ended Life";
    return 0;
}
