#include <life/folder_archive.h>
#include <life/logger.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <fstream>
#include <memory>

namespace boostfs = boost::filesystem;
using boost::system::error_code;
using std::unique_ptr;

namespace life
{
    //////////////////////////////////////////////////////////////////////////
    folder_archive::folder_archive( std::string folder )
    //////////////////////////////////////////////////////////////////////////
    {
        error_code error_code;
        _folder = boostfs::canonical( std::move( folder ), error_code ).native( );

        if ( error_code )
        {
            LOG(fatal) << "Could not find path: " << folder;
            throw file_exception( error_code.message() );
        }
    }

    //////////////////////////////////////////////////////////////////////////
    unique_ptr<std::istream> folder_archive::open( const std::string& filename,
            std::ios_base::openmode mode ) const
    //////////////////////////////////////////////////////////////////////////
    {
        auto path = boostfs::path{ _folder } / filename;
        auto file = std::make_unique<boostfs::ifstream>( path );

        if ( !file->is_open() )
        {
            LOG(error) << "Could not open file: " << path;
            throw file_exception( "No such file or directory" );
        }

        return unique_ptr<std::istream>{ std::move( file ) };
    }

    //////////////////////////////////////////////////////////////////////////
    bool folder_archive::exists( const std::string& filename ) const
    //////////////////////////////////////////////////////////////////////////
    {
        return boostfs::exists( boostfs::path( _folder ) / filename );
    }
}
