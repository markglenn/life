#ifndef _LIFE_COMPOSITE_ARCHIVE_H_
#define _LIFE_COMPOSITE_ARCHIVE_H_

#include "archive.h"
#include <list>

namespace life
{
    class composite_archive : public archive
    {
    public:
        composite_archive() { }
        virtual ~composite_archive( ) { }

        void add_archive( archive* archive );
        void add_archive( std::unique_ptr<archive> archive );

        virtual std::string name( ) const
        {
            return "Composite archive";
        }

        virtual std::unique_ptr<std::istream> open( const std::string& filename,
            std::ios_base::openmode mode = std::ios_base::in ) const;
        virtual bool exists( const std::string& filename ) const;

    private:
        std::list< std::unique_ptr<archive> > _archives;
    };
}

#endif // _LIFE_COMPOSITE_ARCHIVE_H_
