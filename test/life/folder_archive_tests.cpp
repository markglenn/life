#include <fstream>
#include <life/folder_archive.h>
#include "gtest/gtest.h"

TEST(folder_archive_constructor, opens_current_directory) {
    ASSERT_NO_THROW( life::folder_archive( "." ) );
}

TEST(folder_archive_constructor, throws_if_path_doesnt_exist) {
    ASSERT_THROW( life::folder_archive( "/a/b/c/d/e/f/g/h/j" ), life::file_exception );
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

TEST(folder_archive_open, throws_if_file_not_found) {
    life::folder_archive archive( "/dev" );

    ASSERT_THROW( archive.open( "non_existing_file" ), life::file_exception );
}

TEST(folder_archive_open, opens_file_with_leading_slash) {
    life::folder_archive archive( "/dev" );

    EXPECT_TRUE( archive.open( "../dev/zero" ) != NULL );
}
