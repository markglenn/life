#include "life/composite_archive.h"

namespace life
{
    ///////////////////////////////////////////////////////////////////////////
    void composite_archive::add_archive( archive* archive )
    ///////////////////////////////////////////////////////////////////////////
    {
        add_archive( std::unique_ptr<life::archive>( archive ) );
    }

    ///////////////////////////////////////////////////////////////////////////
    void composite_archive::add_archive( std::unique_ptr<archive> archive )
    ///////////////////////////////////////////////////////////////////////////
    {
        _archives.push_back( std::move( archive ) );
    }
    ///////////////////////////////////////////////////////////////////////////
    std::unique_ptr<std::istream> composite_archive::open( const std::string& filename ) const
    ///////////////////////////////////////////////////////////////////////////
    {
        for( const auto& archive : _archives )
        {
            if( archive->exists( filename ) )
                return archive->open( filename );
        }

        throw file_exception( "No such file or directory" );
    }

    ///////////////////////////////////////////////////////////////////////////
    bool composite_archive::exists( const std::string& filename ) const
    ///////////////////////////////////////////////////////////////////////////
    {
        for( const auto& archive : _archives )
        {
            if( archive->exists( filename ) )
                return true;
        }

        return false;
    }
}
