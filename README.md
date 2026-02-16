# ROS2 MicroMouse Robot Navigation (C++17)
ROS2-based MicroMouse robot navigation using DFS with dynamic replanning. Implements Actions, Services, Topics, and YAML Parameters in C++17 with MMS simulator integration.

---

## 📌 Overview

This project implements a ROS2-based navigation system for a simulated MicroMouse robot operating in an unknown **16×16 maze environment** using the MMS simulator.

The robot performs wall-aware **Depth-First Search (DFS)** navigation with dynamic replanning and exposes its behavior through core ROS2 communication patterns:

- **Parameters** (YAML Configuration)
- **Topics** (Real-Time Position Streaming)
- **Services** (Robot Status Queries)
- **Actions** (Goal-Based Navigation with Feedback & Cancellation)

Implemented using **C++17** and **ROS2 Humble**.

---

## 🚀 Key Features

✅ Wall-aware DFS Navigation  
✅ Dynamic Replanning on Wall Detection  
✅ ROS2 Action Server for Navigation Goals  
✅ Action Client with Feedback & Cancellation  
✅ Service Client / Server Architecture  
✅ Real-Time Topic Publisher (`/robot_position`)  
✅ YAML Parameter Configuration  
✅ MMS Simulator Integration  

---

## 🧠 System Architecture

- **micromouse_node** → Core robot control node  
- **navigate_action_client** → Sends navigation goals  
- **get_status_client** → Queries robot state  
- **micromouse_interfaces** → Custom ROS2 action & service definitions  

---

## 🎥 Demo Videos

▶ **Standalone Mode — Parameter Driven Navigation**  
Robot autonomously navigates using YAML parameters.

https://drive.google.com/file/d/1waRerJLt2jLln7QhuRSUskyUhr7DzHM7/view?usp=drive_link

---

▶ **Service Client Interaction — ROS2 Service Communication**  
External node querying robot state via ROS2 services.

https://drive.google.com/file/d/1nG0ZKsFmCJiQJ5onwTpMKooXybwtHEL1/view?usp=drive_link

---

▶ **Action Client / Action Server Interaction — Goal-Based Navigation**  
Goal-driven navigation demonstrating ROS2 Actions, feedback, and cancellation.

https://drive.google.com/file/d/1msblbBuDRnCMMHjjYTiJ9KUk_LyJcBGa/view?usp=drive_link
---

## 🛠 Technologies Used

- **ROS2 Humble**
- **C++17**
- **rclcpp / rclcpp_action**
- **Custom ROS2 Interfaces**
- **MMS Simulator**


