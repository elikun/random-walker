#include "../../src/SS_Commander/Commander.hpp"
#include <gtest/gtest.h>

class CommanderTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }

    Commander *director = new Commander();
};

TEST_F(CommanderTest, StartCommandGeneration_ThreadCreationSuccess) {
    EXPECT_EQ(0, director->startCommandGenerateThread());
}

TEST_F(CommanderTest, StartCommandSend_ThreadCreationSuccess) {
    EXPECT_EQ(0, director->startCommandSendThread());
}
