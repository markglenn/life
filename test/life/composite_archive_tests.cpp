#include <life/composite_archive.h>
#include <life/folder_archive.h>
#include <gtest/gtest.h>

TEST(composite_archive_add_archive, exists_is_true_if_exists_in_sub_archive) {
    life::composite_archive archive;
    archive.add_archive( new life::folder_archive( "/dev" ) );
    ASSERT_TRUE( archive.exists( "null" ) );
}

TEST(composite_archive_add_archive, exists_is_false_if_not_exists_in_sub_archive) {
    life::composite_archive archive;
    archive.add_archive( new life::folder_archive( "/dev" ) );
    ASSERT_FALSE( archive.exists( "bad_file_name" ) );
}

TEST(composite_archive_add_archive, opens_file) {
    life::composite_archive archive;
    archive.add_archive( new life::folder_archive( "/dev" ) );
    ASSERT_TRUE( archive.open( "null" ) != NULL );
}

TEST(composite_archive_add_archive, open_throws_file_exception_if_file_not_found) {
    life::composite_archive archive;
    archive.add_archive( new life::folder_archive( "/dev" ) );
    ASSERT_THROW( archive.open( "bad_file_name" ), life::file_exception );
}
