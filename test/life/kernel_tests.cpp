#include "life/kernel.h"
#include "gtest/gtest.h"

TEST(KernelConstructor, StartsWithNoServices) {
    life::kernel kernel;

    EXPECT_EQ(0, kernel.service_count());
}

