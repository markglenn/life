#include "life/kernel.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

class mock_service : public life::service
{
public:
    mock_service( int priority ) : service( "Mock Service", priority )
    {
        // Default values for mock
        ON_CALL(*this, start()).WillByDefault(Return(true));
        ON_CALL(*this, update(_)).WillByDefault(Return(false));
    }

    MOCK_METHOD1(update, bool (const life::gametime& gametime));
    MOCK_METHOD0(start, bool());
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

        kernel.add_service( new NiceMock<mock_service>{ 1 } );

        for( auto& service : kernel )
            EXPECT_EQ(1, service->priority() );
    }

    TEST(kernel_add_service, adds_service_to_list_by_priority) {
        life::kernel kernel;

        kernel.add_service( new NiceMock<mock_service>{ 2 } );
        kernel.add_service( new NiceMock<mock_service>{ 1 } );

        auto result = kernel.cbegin();

        EXPECT_EQ((*result++)->priority(), 1);
        EXPECT_EQ((*result++)->priority(), 2);
    }

    TEST(kernel_add_service, runs_start_on_service) {
        life::kernel kernel;
        auto service = new NiceMock<mock_service>{1};

        EXPECT_CALL( *service, start())
            .WillOnce(Return(true));

        kernel.add_service( service );
    }

    TEST(kernel_add_service, adds_service_if_start_returns_true) {
        life::kernel kernel;
        auto service = new NiceMock<mock_service>{1};

        EXPECT_CALL( *service, start())
            .WillOnce(Return(true));

        ASSERT_TRUE( kernel.add_service( service ) );
        EXPECT_EQ(1, kernel.service_count());
    }

    TEST(kernel_add_service, does_not_add_service_if_start_returns_false) {
        life::kernel kernel;
        auto service = new NiceMock<mock_service>{ 1 };

        EXPECT_CALL( *service, start())
            .WillOnce(Return(false));

        ASSERT_FALSE( kernel.add_service( service ) );
        EXPECT_EQ(0, kernel.service_count());
    }
}

namespace kernel_run
{
    TEST(kernel_run, calls_update_on_service) {
        life::kernel kernel;
        auto service = new NiceMock<mock_service>{ 1 };

        EXPECT_CALL( *service, start()).WillOnce(Return(true));
        EXPECT_CALL( *service, stop());

        kernel.add_service( service );

        EXPECT_CALL( *service, update( _ ))
            .WillOnce(Return(false));

        kernel.run( );
    }
}

namespace kernel_stop
{
    life::kernel* _kernel;
    bool stop_kernel( )
    {
        _kernel->stop();
        return true;
    }

    TEST(kernel_stop, stops_all_services) {
        life::kernel kernel;
        _kernel = &kernel;

        auto service = new NiceMock<mock_service>{ 1 };

        EXPECT_CALL( *service, update( _ ) )
            .WillOnce( InvokeWithoutArgs( stop_kernel ) );

        EXPECT_CALL( *service, stop( ) );

        kernel.add_service( service );
        kernel.run( );
    }
}
