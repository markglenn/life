#ifndef _LIFE_FOLDER_ARCHIVE_H_
#define _LIFE_FOLDER_ARCHIVE_H_

#include "archive.h"

namespace life
{
    class folder_archive : public archive
    {
    public:
        folder_archive( const std::string& folder );

        virtual ~folder_archive( );
        virtual std::string name( ) const;
        virtual bool open( const std::string& filename, std::ifstream& file );
        virtual bool exists( const std::string& filename );
    };
}

#endif // _LIFE_FOLDER_ARCHIVE_H_
