# 🧊 Cub3D

Cub3D is a **raycasting engine** inspired by the classic *Wolfenstein 3D*.  
The project is part of the **42 curriculum**, focusing on understanding computer graphics, mathematics behind raycasting, and low-level programming in C.

---

## 🚀 Features

- 🕹️ First-person 3D view built from a 2D map  
- 🔦 Raycasting algorithm for wall rendering  
- 🎨 Textured walls, floor, and ceiling  
- 🚪 Doors  
- 🐈 Animated sprites  
- 🎵 Smooth player movement and rotation  

---

## 📸 Preview

> *To be added*

---

## 🛠️ Installation

Clone the repository:

```bash
git clone https://github.com/dmitrijslasko/cub3d.git
cd cub3d
```

---

## 🗺️ Map Format
Maps are defined in .cub files.
Each map includes:
Textures for each wall (North, South, East, West)
Floor and ceiling colors
2D layout with:

1 → Wall
0 → Empty space
N, S, E, W → Player spawn + orientation

Example:
```bash
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

## 🎯 Goals of the Project
Understand the math behind raycasting (DDA algorithm)
Work with MinilibX for window management and graphics
Strengthen skills in C, memory management, and clean coding
Discover how a simple 2D grid can be transformed into a 3D world

## 📚 Resources
Lode's Raycasting Tutorial
MinilibX Documentation
Wolfenstein 3D (Wikipedia)

## 👨‍💻 Authors
Dmitrijs Lasko
Fernanda Vargas
