# 🐭 ROS2 MicroMouse Robot Navigation (C++17)

ROS2-based autonomous MicroMouse navigation system implementing wall-aware Depth-First Search (DFS) with dynamic replanning. Demonstrates core ROS2 communication patterns — **Actions, Services, Topics, and YAML Parameters** — integrated with the MMS simulator.

Built using **C++17** and **ROS2 Humble**.

---

## 📌 Overview

This project implements a modular ROS2 navigation framework for a simulated MicroMouse robot operating in an unknown **16×16 maze environment** using the MMS simulator.

The system emphasizes:

- Deterministic navigation behavior  
- Structured middleware communication  
- Modular ROS2 node architecture  
- Real-time state feedback and monitoring  

The robot performs wall-aware DFS exploration with dynamic replanning while exposing its behavior through ROS2 communication primitives.

---

## 🚀 Key Features

- ✅ Wall-aware DFS navigation with persistent wall mapping  
- ✅ Dynamic replanning upon wall detection  
- ✅ Custom ROS2 Action interface (`NavigateToGoal.action`)  
- ✅ Custom ROS2 Service interface (`GetRobotStatus.srv`)  
- ✅ Action Server with real-time feedback & cancellation support  
- ✅ Action Client for goal-driven navigation  
- ✅ Service Client / Server architecture  
- ✅ Real-time position publisher (`/robot_position`)  
- ✅ Parameter-driven execution modes (Standalone & Action mode)  
- ✅ Full integration with MMS simulator  

---

## 🧠 System Architecture

The project is structured into modular ROS2 packages:
```text
ros2_ws/src/
├── micromouse_interfaces/
│   ├── action/
│   │   └── NavigateToGoal.action
│   └── srv/
│       └── GetRobotStatus.srv
│
└── micromouse_cpp/
    ├── micromouse_node.cpp
    ├── navigate_action_client.cpp
    ├── get_status_client.cpp
    └── config/
        └── params.yaml
        └── params.yaml
```

### Core Components

**micromouse_node**  
Main navigation node implementing:
- DFS-based navigation
- Action server callbacks
- Topic publishing
- Parameter handling

**navigate_action_client**  
Sends goal coordinates to the action server and handles:
- Feedback updates  
- Result handling  
- Ctrl+C cancellation  

**get_status_client**  
Queries robot runtime state via ROS2 service calls.

**micromouse_interfaces**  
Custom action and service definitions with direction constants.

---

## 🔄 Execution Modes

The system supports two execution modes controlled via YAML parameters:

### 1️⃣ Standalone Mode

- `standalone_mode: true`
- Robot navigates immediately using parameters from `params.yaml`
- Publishes position continuously

### 2️⃣ Action Mode

- `standalone_mode: false`
- Robot waits for goal from Action Client
- Provides real-time feedback
- Supports cancellation (Ctrl+C)

---

## 📡 ROS2 Communication Patterns Implemented

### Parameters
YAML-based configuration:
- `goal_x`
- `goal_y`
- `standalone_mode`
- Visualization settings

---

### Topics

**/robot_position**

Publishes:
geometry_msgs::msg::Point
x → robot x position
y → robot y position
z → direction (encoded as 0–3)


---

### Services

**/get_robot_status**

Returns:
- Current position  
- Direction  
- Steps taken  
- Estimated distance to goal  
- Elapsed time  
- Navigation status  

---

### Actions

**/navigate_to_goal**

Supports:
- Goal submission  
- Real-time feedback  
- Result reporting  
- Cancellation handling  

---

## 🎥 Demo Videos

### ▶ Standalone Mode — Parameter Driven Navigation  
Robot autonomously navigates using YAML-defined goal.

https://drive.google.com/file/d/1waRerJLt2jLln7QhuRSUskyUhr7DzHM7/view

---

### ▶ Service Client Interaction — ROS2 Service Communication  
External node querying robot state via ROS2 services.

https://drive.google.com/file/d/1nG0ZKsFmCJiQJ5onwTpMKooXybwtHEL1/view

---

### ▶ Action Client / Server Interaction — Goal-Based Navigation  
Demonstrates:
- Goal submission  
- Feedback streaming  
- Ctrl+C cancellation  

https://drive.google.com/file/d/1msblbBuDRnCMMHjjYTiJ9KUk_LyJcBGa/view

---

## 🛠 Technologies Used

- ROS2 Humble  
- C++17  
- rclcpp  
- rclcpp_action  
- Custom ROS2 Interfaces  
- MMS Simulator  

---


## 🎯 Learning Outcomes

This project demonstrates:

- Designing custom ROS2 interfaces  
- Implementing Action lifecycle management  
- Handling feedback and cancellation  
- Building service-oriented robotics systems  
- Integrating simulation environments with middleware  
- Structuring modular C++ robotics architectures  

---

## 📌 Summary

This project showcases practical ROS2 system design, structured communication patterns, and modular C++ robotics development — emphasizing reliable execution, deterministic behavior, and clean architectural separation.
