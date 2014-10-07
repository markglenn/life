#ifndef _LIFE_SDL_ISTREAM_ADAPTER_H_
#define _LIFE_SDL_ISTREAM_ADAPTER_H_

#include <iostream>
#include <SDL.h>

namespace life
{
    Sint64 istream_seek( struct SDL_RWops *context, Sint64 offset, int whence);
    size_t istream_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum);
    int istream_close( SDL_RWops *context );
    SDL_RWops *SDL_RWFromIStream( std::istream& stream );
}

#endif // _LIFE_SDL_ISTREAM_ADAPTER_H_
