#include "life/kernel.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class mock_service : public life::service
{
public:
    mock_service( int priority ) : service( priority )
    {
        // Default values for mock
        ON_CALL(*this, start(_)).WillByDefault(Return(true));
        ON_CALL(*this, update(_)).WillByDefault(Return(false));
    }

    MOCK_METHOD1(update, bool (const life::gametime& gametime));
    MOCK_CONST_METHOD0(name, std::string());
    MOCK_METHOD1(start, bool( life::kernel* ));
    MOCK_METHOD0(stop, void());
};

namespace kernel_constructor
{
    TEST(kernel_constructor, starts_with_no_services) {
        life::kernel kernel;

        EXPECT_EQ(0, kernel.service_count());
    }
}

namespace kernel_add_service
{
    TEST(kernel_add_service, adds_service_to_list) {
        life::kernel kernel;

        kernel.add_service( new mock_service( 1 ) );
        EXPECT_EQ(1, (*kernel.cbegin())->priority());
    }

    TEST(kernel_add_service, adds_service_to_list_by_priority) {
        life::kernel kernel;

        kernel.add_service( new mock_service( 2 ) );
        kernel.add_service( new mock_service( 1 ) );

        auto result = kernel.cbegin();

        EXPECT_EQ((*result++)->priority(), 1);
        EXPECT_EQ((*result++)->priority(), 2);
    }

    TEST(kernel_add_service, runs_start_on_service) {
        life::kernel kernel;
        auto service = new mock_service(1);

        EXPECT_CALL( *service, start(_))
            .WillOnce(Return(true));

        kernel.add_service( service );
    }

    TEST(kernel_add_service, adds_service_if_start_returns_true) {
        life::kernel kernel;
        auto service = new mock_service(1);

        EXPECT_CALL( *service, start(_))
            .WillOnce(Return(true));

        ASSERT_TRUE( kernel.add_service( service ) );
        EXPECT_EQ(1, kernel.service_count());
    }

    TEST(kernel_add_service, does_not_add_service_if_start_returns_false) {
        life::kernel kernel;
        auto service = new mock_service(1);

        EXPECT_CALL( *service, start(_))
            .WillOnce(Return(false));

        ASSERT_FALSE( kernel.add_service( service ) );
        EXPECT_EQ(0, kernel.service_count());

        delete service;
    }
}

namespace kernel_run
{
    TEST(kernel_run, calls_update_on_service) {
        life::kernel kernel;
        auto service = new mock_service(1);

        EXPECT_CALL( *service, start(_)).WillOnce(Return(true));

        kernel.add_service( service );

        EXPECT_CALL( *service, update( _ ))
            .WillOnce(Return(false));

        kernel.run( );
    }
}

namespace kernel_stop
{
    
}
