#include <life/kernel.h>
#include <life/game_window.h>
#include <life/input_handler.h>
#include <life/folder_archive.h>
#include <life/logger.h>
#include <life/fixed_step_service.h>
#include <life/scene.h>

int main( )
{
    LOG( info ) << "Started Life";

    life::kernel kernel;

    auto window = std::make_shared<life::game_window>( );

    kernel.add_service( window );
    kernel.add_service( std::make_shared<life::input_handler>( ) );
    kernel.add_service( std::make_shared<life::fixed_step_service>( 30 ) );

    auto device = window->device( );
    auto assets = std::make_shared<life::folder_archive>( "../assets" );

    kernel.add_service( std::make_shared<life::scene>( device, assets ) );

    kernel.run( );

    LOG( info ) << "Ended Life";
}
