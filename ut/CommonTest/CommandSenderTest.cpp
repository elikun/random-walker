#include "../../src/Common/CommonConstants.hpp"
#include "../../src/Common/MDL_CommandQueue/CommandQueue.hpp"
#include "../../src/Common/MDL_CommandSender/CommandSender.hpp"
#include <gtest/gtest.h>

#define TEST_NODE_PORT (10005)

class CommandSenderTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }

    CommandQueue cmdQueue;
    CommandSender *cmdSnd = new CommandSender(TEST_NODE_PORT);
};

TEST_F(CommandSenderTest, StartCommandSend_ThreadCreationSuccess) {
    EXPECT_EQ(0, cmdSnd->startCommandSend(cmdQueue));
}
