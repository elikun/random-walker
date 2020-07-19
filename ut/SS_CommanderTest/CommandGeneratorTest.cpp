#include "../../src/Common/CommonConstants.hpp"
#include "../../src/Common/MDL_CommandQueue/CommandQueue.hpp"
#include "../../src/SS_Commander/MDL_CommandGenerator/CommandGenerator.hpp"
#include <gtest/gtest.h>

class CommandGeneratorTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }

    CommandQueue cmdQueue;
    CommandGenerator *cmdGen = new CommandGenerator(CONFIG_INI_FILE);
};

TEST_F(CommandGeneratorTest, StartCommandGeneration_ThreadCreationSuccess) {
    EXPECT_EQ(0, cmdGen->startCommandGeneration(cmdQueue));
}
