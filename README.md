<div align="center">

# 🏓 Ping-Pong-Game (Raylib + C++)

A classic **Paddle Ball (Ping Pong)** game built with **vanilla C++** and the **Raylib** graphics library.  
Fast gameplay, clean visuals, CPU opponent, collision detection, and score tracking.

---

<!-- Badges (optional) -->
![C++](https://img.shields.io/badge/C%2B%2B-17%2B-blue)
![Raylib](https://img.shields.io/badge/raylib-graphics-green)
![Platform](https://img.shields.io/badge/platform-Windows%2FLinux%2FMac-lightgrey)

</div>

---

## 🎮 Gameplay Features

- ✅ **Player vs CPU**
- ✅ **Ball physics** (movement + wall bounce)
- ✅ **Collision detection** (ball vs paddles)
- ✅ **Score system** (player / CPU)
- ✅ **Ball reset** after scoring with randomized direction
- ✅ **Polished arena visuals** (center line + center circle)

---

## 🕹️ Controls

| Action | Key |
|-------|-----|
| Move Paddle Up | `↑` Arrow |
| Move Paddle Down | `↓` Arrow |
| Quit | Close window / `ESC` (depends on platform setup) |

---

## 🧱 Project Structure

```txt
Ping-Pong-Game/
├─ .gitignore
├─ PingPong.cpp        # Game loop, ball + paddle logic, rendering, collisions, scoring
├─ PingPong.h          # Includes, constants (SCREEN_WIDTH/HEIGHT), global score variables
└─ README.md
