# 🤖 CLEAR: Collision-Less Environment-Aware Robot

This repository contains my implementation of the **CLEAR (Collision-Less Environment-Aware Robot) Project**, developed as of my *Automatic Control Lab* final project.

##  Overview
Implemented modules:
- Environment Mapping & Perception 🌐
- Obstacle Detection & Tracking 🚧
- Collision-Free Path Planning 🛤️
- Adaptive Navigation & Control ⚡

These modules enable CLEAR to navigate cluttered and dynamic environments efficiently, avoiding collisions in real time. The project also includes scripts to run full simulations and visualize robot navigation in ROS/Gazebo with a single command.

## 📷 Visual Demonstrations (images + tags)

Below are the screenshots I used in the README along with explicit tags and short captions for each image.  
Place the image files in the repository folder `assets/` and ensure the filenames match exactly.

| Image file (assets/) | Tags | Caption |
|---|---:|---|
| `mapping.png` | `mapping`, `perception`, `ROS`, `environment` | CLEAR building an environment map using sensor fusion. |
| `obstacle-detection.png` | `obstacle-detection`, `LiDAR`, `dynamic`, `tracking` | Real-time detection of static and moving obstacles. |
| `path-planning.png` | `path-planning`, `collision-free`, `RRT`, `A*` | Collision-less path planning around obstacles. |
| `navigation-simulation.png` | `navigation`, `simulation`, `adaptive-control`, `ROS` | Adaptive navigation in a dynamic simulation environment. |
| `hardware-test.png` | `hardware`, `real-robot`, `sensors`, `navigation` | CLEAR performing collision-free navigation on a real robot platform. |

---

### Inline images with captions

### 🔍 Environment Mapping
Builds a real-time map of the surroundings using sensor fusion.

<figure>
  <img src="assets/mapping.png" alt="CLEAR - Environment Mapping" />
  <figcaption><strong>Mapping</strong> · Tags: <code>mapping</code>, <code>perception</code>, <code>ROS</code>, <code>environment</code></figcaption>
</figure>

---

### 🚧 Obstacle Detection
Detects and tracks both static and dynamic obstacles.

<figure>
  <img src="assets/obstacle-detection.png" alt="CLEAR - Obstacle Detection" />
  <figcaption><strong>Obstacle Detection</strong> · Tags: <code>obstacle-detection</code>, <code>LiDAR</code>, <code>dynamic</code>, <code>tracking</code></figcaption>
</figure>

---

### 🛤️ Collision-Free Path Planning
Plans paths that avoid collisions using A*, RRT, and dynamic re-planning.

<figure>
  <img src="assets/path-planning.png" alt="CLEAR - Path Planning" />
  <figcaption><strong>Path Planning</strong> · Tags: <code>path-planning</code>, <code>collision-free</code>, <code>RRT</code>, <code>A*</code></figcaption>
</figure>

---

### ⚡ Adaptive Navigation
Combines planning and control for smooth, real-time navigation.

<figure>
  <img src="assets/navigation-simulation.png" alt="CLEAR - Navigation Simulation" />
  <figcaption><strong>Navigation Simulation</strong> · Tags: <code>navigation</code>, <code>simulation</code>, <code>adaptive-control</code>, <code>ROS</code></figcaption>
</figure>

<figure>
  <img src="assets/hardware-test.png" alt="CLEAR - Real Robot Test" />
  <figcaption><strong>Hardware Test</strong> · Tags: <code>hardware</code>, <code>real-robot</code>, <code>sensors</code>, <code>navigation</code></figcaption>
</figure>

---

## ⚙️ How to Run
```bash
# Run full simulation and visualization
python3 run_all.py
