#include <iostream>
#include "life/kernel.h"
#include <life/game_window.h>
#include <life/input_handler.h>
#include <life/texture.h>
#include <life/folder_archive.h>
#include <life/logger.h>
#include <life/scene.h>
#include <life/fixed_step_service.h>

int main( )
{
    LOG( info ) << "Started Life";

    auto window = std::make_shared<life::game_window>( );
    life::kernel kernel;

    kernel.add_service( window );
    kernel.add_service( std::make_shared<life::input_handler>( ) );
    kernel.add_service( std::make_shared<life::fixed_step_service>( 30 ) );

    auto device = window->device( );

    auto s = life::scene( device );
    
    kernel.add_service( std::make_shared<life::scene>( device ) );
    auto assets = std::make_shared<life::folder_archive>( "../assets" );
    life::texture font{ device, "font.png", assets };

    if ( font.load( ) )
        LOG( info ) << "Font file loaded successfully";

    kernel.run( );

    font.unload( );
    LOG( info ) << "Ended Life";

    return 0;
}
