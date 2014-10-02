#include <life/folder_archive.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <fstream>
#include <memory>

namespace boostfs = boost::filesystem;
using std::unique_ptr;

namespace life
{
    //////////////////////////////////////////////////////////////////////////
    folder_archive::folder_archive( const std::string& folder )
    //////////////////////////////////////////////////////////////////////////
    {
        boost::system::error_code error_code;
        _folder = boostfs::canonical( folder, error_code ).native( );

        if ( error_code )
            throw file_exception( error_code.message() );
    }

    //////////////////////////////////////////////////////////////////////////
    unique_ptr<std::istream> folder_archive::open( const std::string& filename ) const
    //////////////////////////////////////////////////////////////////////////
    {
        auto path = boostfs::path( _folder ) / filename;
        auto file = unique_ptr<std::ifstream>( new boostfs::ifstream( path ) );

        if ( !file->is_open() )
            throw file_exception( "No such file or directory" );

        return unique_ptr<std::istream>( std::move( file ) );
    }

    //////////////////////////////////////////////////////////////////////////
    bool folder_archive::exists( const std::string& filename ) const
    //////////////////////////////////////////////////////////////////////////
    {
        return boostfs::exists( boostfs::path( _folder ) / filename );
    }
}
