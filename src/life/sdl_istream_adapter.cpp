#include <life/sdl_istream_adapter.h>

namespace life
{
    ///////////////////////////////////////////////////////////////////////////
    Sint64 istream_seek( struct SDL_RWops *context, Sint64 offset, int whence )
    ///////////////////////////////////////////////////////////////////////////
    {
        auto stream = ( std::istream* )context->hidden.unknown.data1;

        switch( whence )
        {
            case SEEK_SET:
                stream->seekg( offset, std::ios::beg );
                break;

            case SEEK_CUR:
                stream->seekg( offset, std::ios::cur );
                break;

            case SEEK_END:
                stream->seekg( offset, std::ios::end );
                break;
        }

        return stream->fail( ) ? -1 : static_cast<Sint64>( stream->tellg( ) );
    }

    ///////////////////////////////////////////////////////////////////////////
    size_t istream_read( SDL_RWops *context, void *ptr, size_t size, size_t maxnum )
    ///////////////////////////////////////////////////////////////////////////
    {
        // Exit if we're not reading anything
        if ( size == 0 )
            return -1;

        auto stream = static_cast<std::istream *>( context->hidden.unknown.data1 );
        stream->read( static_cast<char *>( ptr ), size * maxnum );

        return stream->bad( ) ? -1 : stream->gcount( ) / size;
    }

    ///////////////////////////////////////////////////////////////////////////
    int istream_close( SDL_RWops *context )
    ///////////////////////////////////////////////////////////////////////////
    {
        if ( context )
            SDL_FreeRW( context );

        return 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    SDL_RWops* SDL_RW_from_istream( std::istream& stream )
    ///////////////////////////////////////////////////////////////////////////
    {
        auto rwops = SDL_AllocRW();

        if ( rwops ) 
        {
            rwops->seek = istream_seek;
            rwops->read = istream_read;
            rwops->write = nullptr;
            rwops->close = istream_close;
            rwops->hidden.unknown.data1 = static_cast<void *>( &stream );
        }

        return rwops;
    }
}
