# Network Reroute using Dijkstra's Algorithm (C)

> Find the minimum communication delay between two nodes in a network while dynamically avoiding failed nodes.

---

## Table of Contents

- [Overview](#overview)
- [Algorithm](#algorithm)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Input Format](#input-format)
- [Examples](#examples)
- [Edge Cases](#edge-cases)
- [Complexity Analysis](#complexity-analysis)
- [Author](#author)

---

## Overview

In real-world communication networks, nodes (routers, servers) can fail at any time. This project simulates such a scenario — given a weighted, undirected graph of network nodes, it computes the **shortest path (minimum delay)** from a source node to a destination node while **completely bypassing all failed nodes**.

If no valid path exists (due to failures or disconnected topology), the program outputs `inaccessible`.

---

## Algorithm

**Dijkstra's Shortest Path Algorithm** — a greedy, single-source shortest path algorithm for graphs with non-negative edge weights.

### How it works here:
1. Build the graph from CLI arguments (adjacency list style).
2. Mark all failed nodes — they are excluded from relaxation.
3. Run Dijkstra from the source node.
4. Output the minimum distance to the destination, or `inaccessible` if unreachable.

---

## Project Structure

```
network-reroute-dijkstra-c/
│
├── solution.c        # Main source file with Dijkstra implementation
└── README.md         # Project documentation
```

---

## Getting Started

### Prerequisites

- GCC or any C99-compatible compiler

### Compilation

```bash
gcc -o network_reroute solution.c
```

### Running

```bash
./network_reroute <n> <m> <u1> <v1> <w1> ... <failedCount> <f1> ... <source> <dest>
```

---

## Input Format

All input is passed as **command-line arguments** in the following order:

| Position | Value | Description |
|----------|-------|-------------|
| 1 | `n` | Number of nodes (0-indexed) |
| 2 | `m` | Number of edges |
| 3 to 3+3m | `u v w` | Edge between node `u` and `v` with weight `w` (repeated `m` times) |
| next | `failedCount` | Number of failed nodes |
| next | `f1 f2 ...` | Failed node indices |
| last-1 | `source` | Source node |
| last | `dest` | Destination node |

---

## Examples

### Example 1 — Normal Path

**Network topology:**
```
0 --4-- 1
|       |
2       3
 \     /
   --1--
```

**Command:**
```bash
./network_reroute 4 4 0 1 4 0 2 2 2 3 1 1 3 3 0 0 3
```

**Output:**
```
3
```

*(Path: 0 → 2 → 3, total weight = 2 + 1 = 3)*

---

### Example 2 — Node Failure Forces Reroute

```bash
./network_reroute 4 4 0 1 4 0 2 2 2 3 1 1 3 3 1 2 0 3
```

**Output:**
```
7
```

*(Node 2 has failed. Path: 0 → 1 → 3, total weight = 4 + 3 = 7)*

---

### Example 3 — No Path Available

```bash
./network_reroute 4 4 0 1 4 0 2 2 2 3 1 1 3 3 2 1 2 0 3
```

**Output:**
```
inaccessible
```

*(Both intermediate nodes 1 and 2 have failed — no valid path exists)*

---

## Edge Cases

| Scenario | Behavior |
|----------|----------|
| Source node is failed | Outputs `inaccessible` immediately |
| Destination node is failed | Outputs `inaccessible` immediately |
| Source equals destination | Outputs `0` |
| Graph is disconnected | Outputs `inaccessible` |
| No failed nodes | Standard Dijkstra shortest path |

---

## Complexity Analysis

| Metric | Value |
|--------|-------|
| Time Complexity | O(V²) — adjacency matrix + linear min search |
| Space Complexity | O(V + E) |
| Max Nodes Supported | 1005 (`MAXN`) |

> For very large graphs (V > 10⁴), consider upgrading to a **priority queue (min-heap)** based Dijkstra for O((V + E) log V) performance.

---

## Author

**Thamizh**  
Algorithm: Dijkstra's Shortest Path  
Language: C (C99 standard)
