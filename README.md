# Cub3D

**Cub3D** is a 3D graphical project built with **MiniLibX** as part of the 42 School curriculum. It is inspired by the classic **Wolfenstein 3D** game, designed to showcase 2D raycasting techniques to create a pseudo-3D experience. This project is a fundamental exercise in graphics programming, mathematical computation, and game design.

### Gameplay Demo


https://github.com/user-attachments/assets/3473b0af-9ca9-4c94-9c8e-4e1dd710777e


## Features

- **Raycasting Engine**: Implements raycasting to simulate a 3D environment based on a 2D map.  
- **Player Movement**: Real-time interaction with smooth player movement and rotation.  
- **Texture Mapping**: Support for walls with textured surfaces for a more realistic look.  
- **Custom Map Parsing**: Load maps from `.cub` files, with configurable layouts and textures.  
- **Minimap**: Includes a 2D minimap overlay for better navigation.  
- **Real-Time Rendering**: Dynamic frame updates for an immersive gameplay experience.

## Getting Started

### Requirements

- **Operating System**: Linux or macOS.  
- **Libraries**: MiniLibX, and a working X11 server or macOS display system.

### Installation

1. Clone the repository:  
   ```bash  
   git clone https://github.com/LiLZ4CK/Cub3D.git  
   cd cub3d
2. Build the project using Makefile:
   ```bash
   make
3. Run the game:
   ```bash
   ./cub3D map.cub
### Map File Format
Texture Paths: Specify wall textures (e.g., NO, SO, WE, EA).
Colors: Define floor and ceiling colors in RGB.
Map Layout: Use characters (0 for empty space, 1 for walls, N/S/E/W for player spawn).
Example:
```bash
NO ./textures/north.xpm  
SO ./textures/south.xpm  
WE ./textures/west.xpm  
EA ./textures/east.xpm  
F 220,100,0  
C 255,255,255  

111111  
100001  
1010N1  
100001  
111111
```
### Controls
W/A/S/D: Move forward, backward, left, or right.
←/→: Rotate the player’s view.
ESC: Exit the game.

### Features
Raycasting Engine: Implements raycasting to simulate a 3D environment based on a 2D map.
Player Movement: Real-time interaction with smooth player movement and rotation.
Texture Mapping: Support for walls with textured surfaces for a more realistic look.
Custom Map Parsing: Load maps from .cub files, with configurable layouts and textures.
Minimap: Includes a 2D minimap overlay for better navigation.
Real-Time Rendering: Dynamic frame updates for an immersive gameplay experience.

