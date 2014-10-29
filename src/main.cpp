#include <iostream>
#include <life/kernel.h>
#include <life/game_window.h>
#include <life/input_handler.h>
#include <life/texture.h>
#include <life/folder_archive.h>
#include <life/logger.h>
#include <life/scene.h>
#include <life/fixed_step_service.h>
#include <life/shader.h>

int main( )
{
    LOG( info ) << "Started Life";

    life::kernel kernel;

    auto window = std::make_shared<life::game_window>( );

    kernel.add_service( window );
    kernel.add_service( std::make_shared<life::input_handler>( ) );
    kernel.add_service( std::make_shared<life::fixed_step_service>( 30 ) );

    auto device = window->device( );

    auto s = life::scene( device );

    kernel.add_service( std::make_shared<life::scene>( device ) );

    auto assets = std::make_shared<life::folder_archive>( "../assets" );
    life::texture font{ device, "font.png", assets };
    life::shader vertex_shader{ assets, "shaders/cell.vert", life::shader_type::VERTEX_SHADER };
    life::shader fragment_shader{ assets, "shaders/cell.frag", life::shader_type::FRAGMENT_SHADER };

    LOG(error) << vertex_shader.load( );
    LOG(error) << fragment_shader.load( );

    if ( font.load( ) )
        LOG( info ) << "Font file loaded successfully";

    //kernel.run( );

    font.unload( );
    LOG( info ) << "Ended Life";
}
