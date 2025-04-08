cmake_minimum_required(VERSION 3.10)
project(https://education.yandex.ru/handbook/cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(tsk-211 tsk-211.cpp)
target_compile_options(tsk-211 PUBLIC -Wall -Wextra -Werror -pedantic)

add_executable(tsk-212 tsk-212.cpp)
target_compile_options(tsk-212 PUBLIC -Wall -Wextra -Werror -pedantic)

add_executable(tsk-221 tsk-221.cpp)
target_compile_options(tsk-221 PUBLIC -Wall -Wextra -Werror -pedantic)

add_executable(tsk-222 tsk-222.cpp)
target_compile_options(tsk-222 PUBLIC -Wall -Wextra -Werror -pedantic)

add_executable(tsk-241 tsk-241.cpp)
target_compile_options(tsk-241 PUBLIC -Wall -Wextra -Werror -pedantic)

add_executable(tsk-242 tsk-242.cpp)
target_compile_options(tsk-242 PUBLIC -Wall -Wextra -Werror -pedantic)

######################################################################
#                         Google tests
######################################################################

find_package(GTest REQUIRED)

add_executable(gtests tests.cpp)

target_link_libraries(gtests ${GTEST_LIBRARIES})

enable_testing()

add_test(TEST001 gtests)
add_test(TEST002 gtests)
add_test(TEST003 gtests)

######################################################################
#                         Boost tests
######################################################################

# Find Boost and include the unit_test_framework component
find_package (Boost COMPONENTS unit_test_framework REQUIRED)

# Add your test executable
add_executable(btests btests.cpp)

set_target_properties(btests PROPERTIES COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK)

# Link Boost.Test to your test executable
target_link_libraries(btests ${Boost_LIBRARIES})

# Enable testing
enable_testing()

# Add the test executable to CTest
add_test(NAME btest COMMAND btests)