# OpenGL Project Template

Simple C++ OpenGL template using:

* C++17
* CMake
* GLFW 3.5.1
* GLAD 2.0.8
* OpenGL 4.6 Core
* MSVC

## Requirements

Install these tools first:

1. **Visual Studio** with the "Desktop development with C++" workload (MSVC)
2. **CMake** 3.25 or newer
3. **Git**
4. **Python** 3
5. **Make** (to use the `make` commands below)

GLFW and GLAD are downloaded automatically by CMake. `stb_image` is already included in `include/`.

### Python requirements

GLAD 2 generates the OpenGL loader at build time using Python, so the Python packages listed in `requirement.txt` must be installed before running `make init`.

Install them with:

```bash
python -m pip install -r requirement.txt
```

Or, to keep them in a virtual environment:

```bash
python -m venv .venv
.venv\Scripts\activate
python -m pip install -r requirement.txt
```

If you use a virtual environment, keep it activated when running `make init`.

## Setup

Clone the project and install the Python requirements:

```bash
git clone https://github.com/AchmadFauzan1156/OpenGL.git
cd OpenGL
python -m pip install -r requirement.txt
```

Then configure the project:

```bash
make init
```

This will configure CMake and download GLFW and GLAD automatically.

## Build & Run

Build:

```bash
make build
```

Run:

```bash
make run
```

Build and run in one step:

```bash
make mlaku
```

Or rebuild from scratch:

```bash
make rebuild
```

Clean build files:

```bash
make clean
```

## Make Commands

| Command        | Description       |
| -------------- | ----------------- |
| `make init`    | Initialize CMake  |
| `make build`   | Build project     |
| `make rebuild` | Clean and rebuild |
| `make run`     | Run application   |
| `make mlaku`   | Build and run     |
| `make clean`   | Clean build       |

## Project Structure

```text
OpenGLProject/
├── CMakeLists.txt
├── Makefile
├── README.md
├── requirement.txt
├── include/
│   ├── ShaderManager.h
│   └── stb_image.h
├── src/
│   ├── main.cpp
│   ├── ShaderManager.cpp
│   └── stb_image.cpp
├── shaders/
│   ├── main.vs
│   └── main.fs
├── resources/
│   └── basecolor.png
└── build/
```

`build/` is generated automatically by CMake.

Run the application from the project root (as `make run` does), because the texture is loaded from the relative path `resources/basecolor.png`.
