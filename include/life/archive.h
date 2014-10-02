#ifndef _LIFE_ARCHIVE_H_
#define _LIFE_ARCHIVE_H_

#include <iostream>

namespace life
{
    class archive
    {
    public:
        virtual ~archive( ) { }
        virtual std::string name( ) const = 0;
        virtual std::unique_ptr<std::istream> open( const std::string& filename ) = 0;
        virtual bool exists( const std::string& filename ) = 0;
    };
}

#endif // _LIFE_ARCHIVE_H_
