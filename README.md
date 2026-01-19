# 🌀 Fract-ol

A beautiful fractal visualization program built with C and MLX42. This project renders various types of fractals including Mandelbrot, Julia, and Tricorn sets with interactive zoom, pan, and color controls.

![Fractals](https://img.shields.io/badge/Fractals-Mandelbrot%20|%20Julia%20|%20Tricorn-blue)
![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Graphics](https://img.shields.io/badge/Graphics-MLX42-green.svg)

## 📋 Table of Contents
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Fractal Types](#fractal-types)
- [Project Structure](#project-structure)

## ✨ Features

- **Multiple Fractal Types**: Mandelbrot, Julia, and Tricorn fractals
- **Interactive Controls**:
  - Mouse scroll zoom
  - Keyboard navigation (arrow keys)
  - Dynamic color shifting
  - Adjustable iteration depth
- **High Resolution**: 1920x1080 window rendering
- **Real-time Rendering**: Smooth fractal updates with MLX42

## 🔧 Prerequisites

- **Operating System**: macOS (requires Cocoa framework)
- **Compiler**: GCC or Clang
- **Dependencies**:
  - GLFW library
  - CMake
  - OpenGL framework

### Installing GLFW on macOS

```bash
brew install glfw
```

## 🚀 Installation

1. **Clone the repository**:
```bash
git clone https://github.com/alexie26/fract-ol.git
cd fract-ol
```

2. **Build the project**:
```bash
make
```

This will: 
- Clone and build the MLX42 library automatically
- Compile libft and ft_printf dependencies
- Create the `fractol` executable

## 💻 Usage

### Mandelbrot Set
```bash
./fractol mandelbrot
```

### Julia Set
```bash
./fractol julia <real_part> <imaginary_part>
```

Example:
```bash
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.70176 -0.3842
```

### Tricorn Set
```bash
./fractol tricorn
```

## 🎮 Controls

| Key/Action | Function |
|------------|----------|
| **Arrow Keys** | Pan the fractal view (Up, Down, Left, Right) |
| **Mouse Scroll** | Zoom in/out |
| **Keypad +** | Increase iteration depth (more detail) |
| **Keypad -** | Decrease iteration depth (less detail) |
| **Space** | Cycle through color schemes |
| **ESC** | Exit the program |

## 🎨 Fractal Types

### Mandelbrot Set
The Mandelbrot set is defined by the iterative equation:
```
z(n+1) = z(n)² + c
```
where `z(0) = 0` and `c` is the complex coordinate being tested.

### Julia Set
The Julia set uses the equation:
```
z(n+1) = z(n)² + c
```
where `z(0)` is the complex coordinate and `c` is a constant complex parameter.

### Tricorn (Mandelbar) Set
A variation of the Mandelbrot set using the complex conjugate: 
```
z(n+1) = (z̄(n))² + c
```

## 📁 Project Structure

```
fract-ol/
├── fractol.h              # Main header file with structures and prototypes
├── main.c                 # Entry point and fractal type selection
├── fractal_init.c         # Fractal initialization and default settings
├── fractal_render.c       # Core rendering logic
├── fractals.c             # Mathematical implementations (Mandelbrot, Julia, Tricorn)
├── keyboard_mouse.c       # Event handlers for user input
├── shapes_and_colors.c    # Color generation and graphics utilities
├── utils.c                # Helper functions (string to double conversion, etc.)
├── Makefile               # Build configuration
├── libft/                 # Custom C library
├── ft_printf/             # Custom printf implementation
└── MLX42/                 # Graphics library (auto-cloned during build)
```

## 🛠️ Technical Details

- **Resolution**: 1000x1000 pixels (configurable in code)
- **Window Size**: 1920x1080
- **Default Iterations**: 100 (adjustable via keyboard)
- **Color Depth**: 32-bit RGBA
- **Rendering**: Real-time pixel-by-pixel calculation

## 🧮 Algorithm

The program maps each pixel to a point in the complex plane and iterates: 

1. Convert pixel coordinates to complex plane coordinates
2. Apply the fractal-specific iteration formula
3. Count iterations until escape condition (|z| > 2) or max iterations
4. Map iteration count to RGB color value
5. Render pixel with calculated color

## 🧹 Cleaning

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Clean and rebuild
```

## 📝 Notes

- The Julia set requires two parameters (real and imaginary parts of the constant `c`)
- Values are validated to ensure they are proper numbers
- The program uses address sanitizer during compilation for memory safety
- MLX42 is automatically downloaded and built on first compilation

## 🎓 42 School Project

This project is part of the 42 School curriculum, focusing on:
- Computer graphics
- Complex mathematics
- Event-driven programming
- Optimization techniques

## 👤 Author

**roalexan** (alexie26)

---

*Explore the infinite beauty of fractals! 🌌*