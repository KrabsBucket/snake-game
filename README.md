# Snake Engine - Hybrid Pathfinding & RL Project

Project focused on solving snake movement using graph theory and reinforcement learning. The grid is treated as a dynamic weight map (terrain) influenced by functions such as $f(r,c)$.

### Technical Constraints
* **Grid Size:** $m \times m$ where $m = 2k$ ($k \in \mathbb{Z}^+$).
* **Language:** C++17.
* **Build System:** CMake.

### Implementation Status

#### Part 1: Unweighted Algorithms
Completed implementations for grids where all moves have equal cost.
* **Manual:** Keyboard-controlled movement.
* **DFS:** Depth-First Search exploration.
* **BFS:** Breadth-First Search for shortest path.
* **Hamiltonian:** Guaranteed safety cycle visiting every cell once.

#### Part 2: Weighted Algorithms (In Progress)
Current work focuses on pathfinding through non-linear terrain heights.
* **UCS:** Uniform-Cost Search based on cumulative weight.
* **Greedy:** Heuristic-driven Best-First Search.
* **A\*:** Optimal pathfinding using both cost and heuristics.

#### Part 3: Reinforcement Learning (In Progress)
Integration of a model to handle global strategic decisions where local graph solvers fail.
* **Model Storage:** `assets/models/` directory for trained weights.
* **Hybrid Logic:** Utilizing RL to account for the "whole picture" when terrain complexity increases.

### Architecture
* **cpp_engine/include:** Header files for solver and grid logic.
* **cpp_engine/src/unweighted_algorithms:** Implementations for BFS, DFS, and Hamiltonian logic.
* **cpp_engine/src/weighted_algorithms:** Implementations for A*, UCS, and Greedy logic.
* **assets/models:** Directory for single-folder RL model weights.

The rendering system uses a standard coordinate-based grid where 'H' represents the head, 'T' the tail, 'B' the body, and 'F' the food. Empty cells are marked with '.'.