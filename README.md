# Ray Tracing in One Weekend

A C++ implementation of a ray tracer following the "Ray Tracing in One Weekend" book.

## Prerequisites

- C++17 compatible compiler (clang++ or g++)
- Make (optional, but recommended)

## Building

### Using Make (recommended):

```bash
make              # Build the project
make run          # Build and run, output to output/image.ppm
make clean        # Clean build artifacts
```

### Using VS Code:

- Press `Cmd+Shift+B` to build
- Press `F5` to debug
- Use Task: "C++: Build and Run" to build and generate output image

### Manual compilation:

```bash
mkdir -p build
clang++ -std=c++17 -O2 -Wall -Wextra src/*.cpp -o build/raytracer
./build/raytracer > output/image.ppm
```

## Project Structure

```
.
├── src/           # Source files
├── build/         # Compiled binaries (generated)
├── output/        # Rendered images (generated)
├── Makefile       # Build configuration
└── README.md      # This file
```

## Viewing Output

The raytracer outputs PPM format images. To view them:

- Use Preview.app on macOS
- Convert to PNG: `convert output/image.ppm output/image.png` (requires ImageMagick)
- Use any image viewer that supports PPM format
