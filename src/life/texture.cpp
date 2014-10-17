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
        _path{ std::move( path ) },
        _archive{ std::move( archive ) },
        _device{ std::move( device ) },
        _texture{ 0 }
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    texture::~texture( )
    ///////////////////////////////////////////////////////////////////////////
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    GLenum get_texture_format( GLint bpp )
    ///////////////////////////////////////////////////////////////////////////
    {
        switch (bpp) {
            case 4: return GL_RGBA;
            case 3: return GL_RGB;
        }

        LOG( fatal ) << "Unsupported image format with " << bpp << " bytes per pixel";
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////////
    bool texture::load( )
    ///////////////////////////////////////////////////////////////////////////
    {
        if ( auto archive_ptr = _archive.lock( ) )
        {
            auto stream = archive_ptr->open( _path, ios::in | ios::binary );
            auto surface = IMG_Load_RW( SDL_RW_from_istream( *stream ), 1 );

            if( !surface )
            {
                LOG(error) << "Could not load surface: " << _path;
                return false;
            }

            auto bpp = surface->format->BytesPerPixel;
            auto texture_format = get_texture_format( bpp );

            glGenTextures( 1, &_texture );
            glBindTexture( GL_TEXTURE_2D, _texture );

            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

            glTexImage2D( GL_TEXTURE_2D, 0, bpp, surface->w, surface->h, 0,
                    texture_format, GL_UNSIGNED_BYTE, surface->pixels );

            SDL_FreeSurface( surface );

            return true;
        }
        else
        {
            LOG(error) << "Archive has been closed for " << _path;
            return false;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    bool texture::unload( )
    ///////////////////////////////////////////////////////////////////////////
    {
        // Don't unload if the texture isn't loaded
        if ( 0 == _texture )
            return false;

        glDeleteTextures( 1, &_texture );
        _texture = 0;
        return true;
    }
}
