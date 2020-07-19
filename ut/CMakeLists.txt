cmake_minimum_required(VERSION 3.10)

# gtest #include header files
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
message( ${GTEST_INCLUDE_DIRS} )

# Link runUnitTests with test code, gtest, and pthread
add_executable(runUnitTests
               ./CommonTest/CommandQueueTest.cpp ../src/Common/MDL_CommandQueue/CommandQueue.cpp
               ./CommonTest/CommandReceiverTest.cpp ../src/Common/MDL_CommandReceiver/CommandReceiver.cpp
               ./CommonTest/CommandSenderTest.cpp ../src/Common/MDL_CommandSender/CommandSender.cpp
               ./SS_CommanderTest/CommandGeneratorTest.cpp ../src/SS_Commander/MDL_CommandGenerator/CommandGenerator.cpp
               ./SS_CommanderTest/CommanderTest.cpp ../src/SS_Commander/Commander.cpp
               ./SS_EnvironmentTest/EdgeTest.cpp ../src/SS_Environment/MDL_Edge/Edge.cpp
               ./SS_EnvironmentTest/GraphTest.cpp ../src/SS_Environment/MDL_Graph/Graph.cpp)
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
message( ${GTEST_LIBRARIES} )
message( ${GTEST_MAIN_LIBRARIES} )