#include "life/kernel.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class mock_service : public life::service
{
public:
    mock_service( int priority ) : service( priority ){}
    MOCK_METHOD1(update, bool (const life::gametime& gametime));
    MOCK_CONST_METHOD0(name, std::string());
};

TEST(kernel_constructor, starts_with_no_services) {
    life::kernel kernel;

    EXPECT_EQ(0, kernel.service_count());
}

TEST(kernel_add_service, adds_service_to_list) {
    life::kernel kernel;

    kernel.add_service( new mock_service( 1 ) );
    EXPECT_EQ(1, (*kernel.cbegin())->priority());
}

TEST(kernel_add_service_test, adds_service_to_list_by_priority) {
    life::kernel kernel;

    kernel.add_service( new mock_service( 2 ) );
    kernel.add_service( new mock_service( 1 ) );

    auto result = kernel.cbegin();

    EXPECT_EQ((*result++)->priority(), 1);
    EXPECT_EQ((*result++)->priority(), 2);
}
