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
        virtual bool open( const std::string& filename, std::ifstream& file ) = 0;
        virtual bool exists( const std::string& filename ) = 0;
    };
}

#endif // _LIFE_ARCHIVE_H_
