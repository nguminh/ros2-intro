cmake_minimum_required(VERSION 3.8)
project(cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(talker src/talker.cpp)
ament_target_dependencies(talker rclcpp)
ament_target_dependencies(talker example_interfaces)

add_executable(listener src/listener.cpp)
ament_target_dependencies(listener rclcpp)
ament_target_dependencies(listener example_interfaces)

install (TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
