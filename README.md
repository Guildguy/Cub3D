# 🐺 cub3D - Raycasting Engine

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![License](https://img.shields.io/badge/License-MIT-green)

## 🗣️ About

**cub3D** is a project inspired by the world-famous **Wolfenstein 3D** game, which was the first FPS ever developed. It explores the **Raycasting** technique to generate 3D representations from a 2D map structure.

This project allowed me to improve my skills in:
* **C Programming:** Rigorous memory management and low-level logic.
* **Mathematics:** Applying trigonometry for raycasting and player movement vectors.
* **Graphics:** Pixel manipulation using the MiniLibX library.
* **Parsing:** Validating complex map configurations (.cub files).

![Gameplay Screenshot](path/to/your/screenshot_or_gif.png)
*(Add a screenshot here!)*

## 🎮 Features

* **Raycasting Rendering:** Real-time 3D projection.
* **Texture Mapping:** Different textures for North, South, East, and West walls.
* **Player Movement:** Smooth movement (WASD) and camera rotation.
* **Map Parsing:** Reads `.cub` files to configure the maze and textures.
* **Collision Detection:** Prevents the player from walking through walls.
* **Leak Free:** Rigorously tested with Valgrind to ensure zero memory leaks.

## 🛠️ Installation & Usage

Since this project uses **MiniLibX** (a graphical library for students), it requires some X11 dependencies to run on Linux.

### 1. Install Dependencies (Linux)
You need `xorg`, `libxext-dev`, and `zlib1g-dev`. On Ubuntu/Debian:

```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
