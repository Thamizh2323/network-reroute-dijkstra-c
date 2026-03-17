# Network Reroute using Dijkstra (C)

This project solves a network routing problem where the goal is to find the
minimum communication delay between two nodes while avoiding failed nodes.

## Problem Overview

- Graph is weighted and undirected
- Some nodes may fail and cannot be used
- Find shortest path from source to destination
- If no path exists → return "inaccessible"

## Algorithm Used

Dijkstra's Shortest Path Algorithm

## Features

- CLI argument-based input
- Handles failed nodes
- Efficient path calculation
- Clean and readable C implementation

## Input Format

n m edge_data failed_count failed_nodes source destination

### Example
