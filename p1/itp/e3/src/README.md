# Height Map Generator

A simple project that generates height maps using the Diamond-Square algorithm and renders them as PPM images with customizable color palettes.

## 📁 Project Structure

```
src/
├── main.cpp              # Main program entry point
├── map.h                 # HeightMap class header
├── map.cpp               # HeightMap implementation (Diamond-Square algorithm)
├── image.h               # Image class header
├── image.cpp             # Image handling and PPM output
├── palette.h             # Color palette class header
├── palette.cpp           # Palette management and color interpolation
├── colors_gray.txt       # Grayscale color palette
├── colors_brazil.txt     # Brazil flag colors palette
├── colors_base.txt       # Basic color palette
├── colors.txt            # Default color palette
├── results/              # Generated output images
│   ├── minimap.ppm
│   ├── minimap_gray.ppm
│   ├── minimap_gray_shadow.ppm
│   ├── minimap_brazil.ppm
│   ├── minimap_brazil_shadow.ppm
│   └── minimap_shadow.ppm
├── tests/
│   ├── data/
│   ├── test_image.cpp
│   ├── test_palette.cpp
│   ├── doctest.h
├── .gitignore
├── README.md
```

## 🚀 How to Run

### Prerequisites
- Linux ;-;
- C++ compiler (g++)

### Compilation
```bash
cd src
g++ -std=c++17 -o heightmap main.cpp map.cpp image.cpp palette.cpp
./heightmap
```

### Configuration
The program can be modified in `main.cpp` to:
- Change map size (currently set to 10, creating a 1025x1025 map)
- Adjust roughness parameter (currently 0.5)
- Use different color palettes
- Enable/disable shadow effects

## 🎨 Color Palettes

The project includes several predefined color palettes, all palettes should 
setted to use the numbers between 0 and 1.

- **`colors_gray.txt`**: 32-step grayscale gradient
- **`colors_brazil.txt`**: Brazil flag colors (green, yellow, blue, white)
- **`colors.txt`**: Default color palette

## 📊 Results

<!-- ![Minimap](./results/minimap.ppm)
![Minimap Gray](./results/minimap_gray.ppm)
![Minimap Gray Shadow](./results/minimap_gray_shadow.ppm)
![Minimap Brazil](./results/minimap_brazil.ppm)
![Minimap Brazil Shadow](./results/minimap_brazil_shadow.ppm)
![Minimap Shadow](./results/minimap_shadow.ppm) -->

## 🔬 Technical Details

### Diamond-Square Algorithm
The terrain generation uses the Diamond-Square algorithm:
1. **Initialize corners** with random values
2. **Diamond step**: Calculate center points using corner averages
3. **Square step**: Calculate edge midpoints using adjacent points
4. **Iterate**: Repeat with smaller step sizes and reduced displacement
5. **Normalize**: Scale all values to [0,1] range

### Shadow Calculation
Shadows are calculated by comparing each pixel with its northwest neighbor:
- If the neighbor is higher, the current pixel is darkened by 50%
- This creates realistic shadow effects on slopes

## What I Learn

This project is a comprehensive overview of the class "Introdução a Técnicas de Programação (DIM0151)" in the course of Computer Science at UFRN (Universidade Federal do Rio Grande do Norte). The course was taught using C++. Through this project, I learned more about:
- C++ array operations
- Matrix operations (2D) and implementation of a matrix using a 1D array
- Dynamic memory allocation
- Functions
- Pointer operations
- Structured data and enums
- Classes
- Testing (Doctest)
- File I/O operations
- Procedural generation algorithms (Diamond-Square)
- PPM image format
...

## What i can improve
- Make more tests to map class
- Integrate with more algorithms like hill-shadding
- Use make tool to setup build and commands
- Documentation