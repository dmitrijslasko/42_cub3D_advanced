# 🧊 Cub3D

## Score:
✅ 125/125 (with bonus)
⚠️ Fully compliant with 42 Norm code style rules  
🧹 No memory leaks  

This version was used as a **basis for a more advanced raycasting engine** with many additional features:  
[Sushi Ninja 3D – Cub3D Advanced] https://github.com/dmitrijslasko/42_cub3D_advanced

---

## 🚀 Features

- 🕹️ First-person 3D view built from a 2D map  
- 🔦 Raycasting algorithm for wall rendering  
- 🎨 Textured walls with distance shadows, single-color floor and ceiling
- Open-air moving sky
- 🚪 Doors (opening and closing on button press)  
- 🐈 Animated sprites (simple animation with 2 frames)
- 🎵 Smooth player movement and rotation
- Audio implemented with SDL2 library

---

## 📸 Preview (Youtube video)

<a href="https://www.youtube.com/watch?v=zGh0d-RLmI8" target="_blank">
  <img src="https://img.youtube.com/vi/zGh0d-RLmI8/maxresdefault.jpg" alt="Watch the video">
</a>

---

## 🛠️ Installation

Clone the repository:

```bash
git clone https://github.com/dmitrijslasko/42_cub3d.git
cd cub3d
```

---

## 🗺️ Map Format
Maps are defined in .cub files. Each map includes:  
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

## Questions? 🤔
**Feel free to contact me:**
**Slack:** @dmlasko  
**E-mail**: dmitrijs.lasko@gmail.com  
**Telegram:** @lalamoose  
