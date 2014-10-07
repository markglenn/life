#include "life/gametime.h"
#include "gtest/gtest.h"
#include <thread>
#include <chrono>

using namespace std::literals;
using namespace std::literals::chrono_literals;

TEST(gametime_constructor, StartsWithZeroDuration) {
    life::gametime gametime;

    EXPECT_EQ(0, gametime.total_time());
}

TEST(gametime_update, UpdatesTotalTime) {
    life::gametime gametime;

    std::this_thread::sleep_for( 2ms );
    gametime.update();
    EXPECT_TRUE(gametime.total_time() > 0.0);
}

TEST(gametime_update, UpdatesCurrentStep) {
    life::gametime gametime;

    // Delay a little and update twice
    std::this_thread::sleep_for( 2ms );
    gametime.update( );
    std::this_thread::sleep_for( 2ms );
    gametime.update( );

    EXPECT_TRUE( gametime.current_step() > 0.0);
    EXPECT_TRUE( gametime.total_time() > gametime.current_step() );
}
