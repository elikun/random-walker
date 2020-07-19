cmake_minimum_required(VERSION 3.10)

# Qt5
# https://doc.qt.io/qt-5/cmake-variable-reference.html
# https://doc.qt.io/qt-5/qtmodules.html
find_package(Qt5 COMPONENTS Core REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})
message("-- Found Qt5:")
message(${Qt5Core_INCLUDE_DIRS})

# gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
message(${GTEST_INCLUDE_DIRS})

# Define source code components (test code and production code) for run_all_unit_tests
add_executable( run_all_unit_tests
                ./CommonTest/CommandQueueTest.cpp ../src/Common/MDL_CommandQueue/CommandQueue.cpp
                ./CommonTest/CommandReceiverTest.cpp ../src/Common/MDL_CommandReceiver/CommandReceiver.cpp
                ./CommonTest/CommandSenderTest.cpp ../src/Common/MDL_CommandSender/CommandSender.cpp
                ./SS_CommanderTest/CommandGeneratorTest.cpp ../src/SS_Commander/MDL_CommandGenerator/CommandGenerator.cpp
                ./SS_CommanderTest/CommanderTest.cpp ../src/SS_Commander/Commander.cpp
                ./SS_EnvironmentTest/EdgeTest.cpp ../src/SS_Environment/MDL_Edge/Edge.cpp
                ./SS_EnvironmentTest/GraphTest.cpp ../src/SS_Environment/MDL_Graph/Graph.cpp )

# Link run_all_unit_tests with test code, Qt5, gtest, and pthread
target_link_libraries(run_all_unit_tests ${Qt5Core_LIBRARIES} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
message(${GTEST_LIBRARIES})
message(${GTEST_MAIN_LIBRARIES})