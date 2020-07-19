#include "../../src/Common/MDL_CommandQueue/CommandQueue.hpp"
#include "gtest/gtest.h"

class CommandQueueTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }

    CommandQueue cmdQueue;
};

TEST_F(CommandQueueTest, DefaultConstructor_EmptyQueueCreated) {
    EXPECT_TRUE(cmdQueue.isEmpty());
    EXPECT_EQ(0, cmdQueue.size());
}

TEST_F(CommandQueueTest, PushBack_SizeIsIncreased) {
    EXPECT_TRUE(cmdQueue.isEmpty());
    EXPECT_EQ(0, cmdQueue.size());

    for (int i = 0; i < 4; i++)
    {
        cmdQueue.push_back(i);
        EXPECT_FALSE(cmdQueue.isEmpty());
        EXPECT_EQ(i + 1, cmdQueue.size());
    }
}

TEST_F(CommandQueueTest, PopFront_SizeIsDecreased) {
    EXPECT_TRUE(cmdQueue.isEmpty());
    EXPECT_EQ(0, cmdQueue.size());

    for (int i = 0; i < 4; i++)
    {
        cmdQueue.push_back(i);
    }

    for (int i = 3; i >= 0; i--)
    {
        EXPECT_FALSE(cmdQueue.isEmpty());
        EXPECT_EQ(i + 1, cmdQueue.size());
        cmdQueue.pop_front();
    }

    EXPECT_TRUE(cmdQueue.isEmpty());
    EXPECT_EQ(0, cmdQueue.size());
}

TEST_F(CommandQueueTest, PopFront_CorrectValueObtained) {
    EXPECT_TRUE(cmdQueue.isEmpty());
    EXPECT_EQ(0, cmdQueue.size());

    for (int i = 0; i < 4; i++)
    {
        cmdQueue.push_back(i);
    }

    for (int i = 0; i < 4; i++)
    {
        EXPECT_FALSE(cmdQueue.isEmpty());
        EXPECT_EQ(i, cmdQueue.pop_front());
    }

    EXPECT_TRUE(cmdQueue.isEmpty());
    EXPECT_EQ(0, cmdQueue.size());
}
