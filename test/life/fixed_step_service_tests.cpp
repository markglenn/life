#include <life/fixed_step_service.h>
#include <gtest/gtest.h>
#include <chrono>
#include <thread>

using namespace std::literals;
using namespace std::literals::chrono_literals;

TEST(fixed_step_service_update, delays_for_frame) {
    auto gametime = life::gametime{};
    auto service = life::fixed_step_service{ 100 };

    gametime.update( );
    service.update(gametime);
    gametime.update( );

    // We expect to have slept for at least 10ms
    ASSERT_TRUE( gametime.total_time( ) >= 0.01 );
    ASSERT_TRUE( gametime.total_time( ) <= 0.02 );
}

TEST(fixed_step_service_update, doesnt_delay_if_past_frame_time) {
    auto gametime = life::gametime{};
    auto service = life::fixed_step_service{ 100 };

    gametime.update( );
    std::this_thread::sleep_for( 20ms );
    service.update(gametime);
    gametime.update( );

    // We expect to have slept for at least 10ms
    ASSERT_TRUE( gametime.total_time( ) <= 0.03 );
}
