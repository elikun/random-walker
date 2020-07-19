#include "../../src/Common/CommonConstants.hpp"
#include "../../src/SS_Environment/MDL_Edge/Edge.hpp"
#include "../../src/SS_Environment/MDL_Graph/Graph.hpp"
#include <gtest/gtest.h>

#define CONF_INI_TEST_FILE_ALL      "SS_EnvironmentTest/conf_GraphTest_AllEdges.ini"
#define CONF_INI_TEST_FILE_EMPTY    "SS_EnvironmentTest/conf_GraphTest_NoEdges.ini"
#define CONF_INI_TEST_FILE_REPEATED "SS_EnvironmentTest/conf_GraphTest_RepeatedEdges.ini"
#define CONF_INI_TEST_FILE_UNIQUE   "SS_EnvironmentTest/conf_GraphTest_UniqueEdges.ini"

extern bool operator== (const Edge &e1, const Edge &e2);

class GraphTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }

    Graph graph;
};

TEST_F(GraphTest, Init_AllHorizontal) {
    graph.init(CONF_INI_TEST_FILE_ALL);
    std::vector<Edge> edges = graph.getEdges();
    Edge e1;
    Edge e2;

    // Check all possible horizontal edges
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 80; j += 10) {
            e1.setV1(i + j);
            e1.setV2(i + j + 10);
            e2.setV1(i + j + 10);
            e2.setV2(i + j);

            EXPECT_TRUE(std::find(edges.begin(), edges.end(), e1) != edges.end() ||
                        std::find(edges.begin(), edges.end(), e2) != edges.end());
        }
    }
}

TEST_F(GraphTest, Init_AllVertical) {
    graph.init(CONF_INI_TEST_FILE_ALL);
    std::vector<Edge> edges = graph.getEdges();
    Edge e1;
    Edge e2;

    // Check all possible vertical edges
    for (int i = 0; i <= 90; i += 10) {
        for (int j = 0; j <= 8; j++) {
            e1.setV1(i + j);
            e1.setV2(i + j + 1);
            e2.setV1(i + j + 1);
            e2.setV2(i + j);

            EXPECT_TRUE(std::find(edges.begin(), edges.end(), e1) != edges.end() ||
                        std::find(edges.begin(), edges.end(), e2) != edges.end());
        }
    }
}

TEST_F(GraphTest, Init_Empty) {
    graph.init(CONF_INI_TEST_FILE_EMPTY);
    std::vector<Edge> edges = graph.getEdges();

    EXPECT_EQ(0, edges.size());
}

TEST_F(GraphTest, Init_RepeatedEdges) {
    graph.init(CONF_INI_TEST_FILE_REPEATED);
    std::vector<Edge> edges = graph.getEdges();

    EXPECT_EQ(1, edges.size());
}

TEST_F(GraphTest, Init_UniqueEdges) {
    graph.init(CONF_INI_TEST_FILE_UNIQUE);
    std::vector<Edge> edges = graph.getEdges();

    EXPECT_EQ(5, edges.size());
}

TEST_F(GraphTest, IsValidMovement_Valid) {
    graph.init(CONF_INI_TEST_FILE_ALL);

    // Default current vertex is 00
    EXPECT_TRUE(graph.isValidMovement(1)); // DOWN
    EXPECT_TRUE(graph.isValidMovement(3)); // RIGHT
}

TEST_F(GraphTest, IsValidMovement_Invalid) {
    graph.init(CONF_INI_TEST_FILE_ALL);

    // Default current vertex is 00
    EXPECT_FALSE(graph.isValidMovement(0)); // UP
    EXPECT_FALSE(graph.isValidMovement(2)); // LEFT
}

TEST_F(GraphTest, EdgeComparison_Same) {
    Edge e1(00, 01);
    Edge e2(00, 01);

    EXPECT_TRUE(e1 == e2);
}

TEST_F(GraphTest, EdgeComparison_Different) {
    Edge e1(00, 01);
    Edge e2(01, 00);

    EXPECT_FALSE(e1 == e2);
}
