/**
 * @file micromouse_node.cpp
 * @brief MicroMouse ROS2 node with DFS navigation
 *
 * Complete the TODOs to implement the ROS2 node
 *
 * Algorithm: Depth-First Search (DFS) with dynamic replanning.
 * - Uses a stack (LIFO) to explore paths
 * - Does NOT guarantee shortest path - finds any valid path
 * - Neighbor priority order: North, East, South, West
 * - Replans when walls are discovered that block the current path
 *
 * Point values are shown in each TODO comment.
 */

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <functional>
#include <geometry_msgs/msg/point.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <set>
#include <string>
#include <thread>
#include <vector>

#include "micromouse_cpp/maze_control_api.hpp"
#include "micromouse_cpp/micromouse_node.hpp"
#include "micromouse_interfaces/action/navigate_to_goal.hpp"
#include "micromouse_interfaces/srv/get_robot_status.hpp"

// =============================================================================
// Main
// =============================================================================

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<micromouse::MicroMouseNode>();

  if (node->is_standalone_mode()) {
    // Run navigation in separate thread so ROS2 services still work
    std::thread nav_thread([node]() {
      node->run_navigation();
      rclcpp::shutdown();
    });

    rclcpp::spin(node);

    if (nav_thread.joinable()) {
      nav_thread.join();
    }
  } else {
    // Use MultiThreadedExecutor to allow feedback publishing while action executes
    RCLCPP_INFO(node->get_logger(), "Waiting for action client...");
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
  }

  rclcpp::shutdown();
  return 0;
}