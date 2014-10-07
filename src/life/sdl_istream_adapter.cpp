#include <life/sdl_istream_adapter.h>

namespace life
{
    Sint64 istream_seek( struct SDL_RWops *context, Sint64 offset, int whence)
    {
        auto stream = ( std::istream* )context->hidden.unknown.data1;

        if ( whence == SEEK_SET )
            stream->seekg( offset, std::ios::beg );
        else if ( whence == SEEK_CUR )
            stream->seekg( offset, std::ios::cur );
        else if ( whence == SEEK_END )
             stream->seekg( offset, std::ios::end );

        return stream->fail( ) ? -1 : ( int )stream->tellg( );
    }


    size_t istream_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum)
    {
        if ( size == 0 ) return -1;
        std::istream* stream = (std::istream*) context->hidden.unknown.data1;
        stream->read( (char*)ptr, size * maxnum );

        return stream->bad() ? -1 : stream->gcount() / size;
    }

    int istream_close( SDL_RWops *context )
    {
        if ( context ) {
            SDL_FreeRW( context );
        }
        return 0;
    }


    SDL_RWops *SDL_RWFromIStream( std::istream& stream )
    {
        SDL_RWops *rwops;
        rwops = SDL_AllocRW();

        if ( rwops != NULL ) 
        {
            rwops->seek = istream_seek;
            rwops->read = istream_read;
            rwops->write = NULL;
            rwops->close = istream_close;
            rwops->hidden.unknown.data1 = &stream;
        }
        return rwops;
    }
}
