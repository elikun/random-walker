#include "../../src/Common/CommonConstants.hpp"
#include "../../src/Common/MDL_CommandQueue/CommandQueue.hpp"
#include "../../src/Common/MDL_CommandReceiver/CommandReceiver.hpp"
#include <gtest/gtest.h>

#define TEST_NODE_PORT (10004)

class CommandReceiverTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }

    CommandQueue cmdQueue;
    CommandReceiver *cmdRcv = new CommandReceiver(TEST_NODE_PORT);
};

TEST_F(CommandReceiverTest, StartCommandReceive_ThreadCreationSuccess) {
    EXPECT_EQ(0, cmdRcv->startCommandReceive(cmdQueue));
}
