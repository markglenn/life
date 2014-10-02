#include <life/folder_archive.h>
#include <boost/filesystem.hpp>

namespace life
{
    folder_archive::folder_archive( const std::string& folder )
    {

    }

    folder_archive::~folder_archive( ) {}

    std::string folder_archive::name( ) const
    {
        return "Test";
    }

    bool folder_archive::open( const std::string& filename, std::ifstream& file )
    {
        return false;
    }

    bool folder_archive::exists( const std::string& filename )
    {
        return false;
    }
}
