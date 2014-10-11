#include <life/logger.h>
#include <life/texture.h>
#include <life/sdl_istream_adapter.h>
#include <SDL_image.h>

using std::ios;

namespace life
{
    ///////////////////////////////////////////////////////////////////////////
    texture::texture( std::shared_ptr<life::device> device, std::string path,
            std::shared_ptr<life::archive> archive ) :
        resource{ std::move( path ), std::move( archive ) },
        _device{ std::move( device ) },
        _texture{ nullptr }
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    texture::~texture( )
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    bool texture::load( )
    ///////////////////////////////////////////////////////////////////////////
    {
        auto stream = archive( )->open( path( ), ios::in | ios::binary );
        auto surface = IMG_Load_RW( SDL_RW_from_istream( *stream ), 1 );

        if( !surface )
        {
            LOG(error) << "Could not load surface: " << path( );
            return false;
        }

        _texture = SDL_CreateTextureFromSurface( _device->renderer( ), surface );

        SDL_FreeSurface( surface );

        if( !_texture )
        {
            LOG(error) << "Could not create texture from image: " << path( );
            return false;
        }

        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    bool texture::unload( )
    ///////////////////////////////////////////////////////////////////////////
    {
        // Don't unload if the texture isn't loaded
        if ( nullptr == _texture )
            return false;

        SDL_DestroyTexture( _texture );
        _texture = nullptr;

        return true;
    }
}
