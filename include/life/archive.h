#ifndef _LIFE_ARCHIVE_H_
#define _LIFE_ARCHIVE_H_

#include <iostream>

namespace life
{
    class file_exception : public std::exception
    {
    public:
        file_exception( const std::string& message ) : error_message( message) { }
        ~file_exception( ) throw( ) {}

        const char *what( ) const throw( )
        {
            return error_message.c_str();
        }

    private:
        std::string error_message;
    };

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
