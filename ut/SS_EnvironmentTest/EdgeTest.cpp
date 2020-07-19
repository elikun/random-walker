#include "../../src/Common/CommonConstants.hpp"
#include "../../src/SS_Environment/MDL_Edge/Edge.hpp"
#include <gtest/gtest.h>

class EdgeTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }

};

TEST_F(EdgeTest, DefaultConstructorAndGetters) {
    Edge *e = new Edge();
    EXPECT_EQ(0, e->getV1());
    EXPECT_EQ(0, e->getV2());
}

TEST_F(EdgeTest, ConstructorAndGetters) {
    Edge e1(12, 22);
    EXPECT_EQ(12, e1.getV1());
    EXPECT_EQ(22, e1.getV2());

    Edge e2(64, 65);
    EXPECT_EQ(64, e2.getV1());
    EXPECT_EQ(65, e2.getV2());
}

TEST_F(EdgeTest, Setters_WithinRange) {
    Edge e1;
    e1.setV1(39);
    EXPECT_EQ(39, e1.getV1());
    e1.setV2(29);
    EXPECT_EQ(29, e1.getV2());

    e1.setV1(0);
    EXPECT_EQ(0, e1.getV1());
    e1.setV2(99);
    EXPECT_EQ(99, e1.getV2());
}

TEST_F(EdgeTest, Setters_OutOfRange) {
    Edge e1(34, 35);
    e1.setV1(-1);
    EXPECT_EQ(34, e1.getV1());
    e1.setV2(100);
    EXPECT_EQ(35, e1.getV2());
}

TEST_F(EdgeTest, IsValidEdge_Valid) {
    Edge e1(0, 1);
    EXPECT_TRUE(e1.isValidEdge());

    e1.setV1(10);
    e1.setV2(0);
    EXPECT_TRUE(e1.isValidEdge());

    e1.setV1(99);
    e1.setV2(89);
    EXPECT_TRUE(e1.isValidEdge());

    e1.setV1(98);
    e1.setV2(99);
    EXPECT_TRUE(e1.isValidEdge());
}

TEST_F(EdgeTest, IsValidEdge_Invalid) {
    Edge e1(0, 91);
    EXPECT_FALSE(e1.isValidEdge());

    e1.setV1(19);
    e1.setV2(0);
    EXPECT_FALSE(e1.isValidEdge());
}
