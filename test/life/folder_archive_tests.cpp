#include <fstream>
#include <life/folder_archive.h>
#include "gtest/gtest.h"

TEST(folder_archive_constructor, opens_current_directory) {
    life::folder_archive archive( "." );

    EXPECT_EQ( ".", archive.name() );
}

TEST(folder_archive_exists, returns_true_if_file_exists) {
    life::folder_archive archive( "/dev" );

    EXPECT_TRUE( archive.exists( "null" ) );
}

TEST(folder_archive_exists, returns_false_if_file_doesnt_exist) {
    life::folder_archive archive( "/dev" );

    EXPECT_FALSE( archive.exists( "non_existing_file" ) );
}

TEST(folder_archive_open, opens_file_for_reading) {
    life::folder_archive archive( "/dev" );

    EXPECT_TRUE( archive.open( "zero" ) != NULL );
}

TEST(folder_archive_open, returns_null_for_file_not_found) {
    life::folder_archive archive( "/dev" );

    EXPECT_TRUE( archive.open( "non_existing_file" ) == NULL );
}
