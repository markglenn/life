#include <life/folder_archive.h>
#include "gtest/gtest.h"

TEST(folder_archive_constructor, opens_current_directory) {
    life::folder_archive archive( "." );

    EXPECT_EQ( ".", archive.name() );
}

