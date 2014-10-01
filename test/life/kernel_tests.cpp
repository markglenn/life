#include "life/kernel.h"
#include "gtest/gtest.h"

TEST(kernel_constructor, StartsWithNoServices) {
    life::kernel kernel;

    EXPECT_EQ(0, kernel.service_count());
}

TEST(kernel_add_service, AddsServiceToList) {
    life::kernel kernel;

    kernel.add_service( new life::service( 1 ) );
    EXPECT_EQ(1, (*kernel.cbegin())->get_priority());
}

TEST(kernel_add_service_test, AddsServiceToListByPriority) {
    life::kernel kernel;

    kernel.add_service( new life::service( 2 ) );
    kernel.add_service( new life::service( 1 ) );

    auto result = kernel.cbegin();

    EXPECT_EQ((*result++)->get_priority(), 1);
    EXPECT_EQ((*result++)->get_priority(), 2);
}
