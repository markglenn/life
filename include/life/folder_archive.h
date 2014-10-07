#ifndef _LIFE_FOLDER_ARCHIVE_H_
#define _LIFE_FOLDER_ARCHIVE_H_

#include "archive.h"

namespace life
{
    class folder_archive : public archive
    {
    public:
        folder_archive( const std::string& folder );

        virtual ~folder_archive( ) { }
        virtual std::string name( ) const { return _folder; }

        virtual std::unique_ptr<std::istream> open( const std::string& filename,
                std::ios_base::openmode mode = std::ios_base::in ) const;
        virtual bool exists( const std::string& filename ) const;

    private:

        std::string _folder;
    };
}

#endif // _LIFE_FOLDER_ARCHIVE_H_
