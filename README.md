# OpenGL Project Template

Template C++ OpenGL sederhana yang menggunakan:

* C++17
* CMake
* GLFW 3.5.1
* GLAD 2.0.8
* OpenGL 4.6 Core
* MSVC

## Requirements

Install dulu tool berikut:

1. **Visual Studio** dengan workload "Desktop development with C++" (MSVC)
2. **CMake** versi 3.25 atau lebih baru
3. **Git**
4. **Python** 3
5. **Make** (untuk menjalankan perintah `make` di bawah)

GLFW dan GLAD di-download otomatis oleh CMake. `stb_image` sudah tersedia di folder `include/`.

### Python Requirements

GLAD 2 membuat loader OpenGL saat proses build menggunakan Python, jadi package Python yang ada di `requirement.txt` harus di-install sebelum menjalankan `make init`.

Install dengan:

```bash
python -m pip install -r requirement.txt
```

Atau, kalau ingin memakai virtual environment:

```bash
python -m venv .venv
.venv\Scripts\activate
python -m pip install -r requirement.txt
```

Kalau memakai virtual environment, pastikan tetap aktif saat menjalankan `make init`.

## Setup

Clone project lalu install Python requirements:

```bash
git clone https://github.com/AchmadFauzan1156/OpenGL.git
cd OpenGL
python -m pip install -r requirement.txt
```

Kemudian konfigurasi project:

```bash
make init
```

Perintah ini mengonfigurasi CMake serta men-download GLFW dan GLAD secara otomatis.

## Build & Run

Build:

```bash
make build
```

Run:

```bash
make run
```

Build dan run sekaligus:

```bash
make mlaku
```

Atau rebuild dari awal:

```bash
make rebuild
```

Bersihkan hasil build:

```bash
make clean
```

## Make Commands

| Command        | Keterangan                    |
| -------------- | ----------------------------- |
| `make init`    | Inisialisasi CMake            |
| `make build`   | Build project                 |
| `make rebuild` | Clean lalu build ulang        |
| `make run`     | Jalankan aplikasi             |
| `make mlaku`   | Build lalu jalankan           |
| `make clean`   | Bersihkan hasil build         |

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

Folder `build/` dibuat otomatis oleh CMake.

Jalankan aplikasi dari root project (seperti yang dilakukan `make run`), karena texture dimuat dari path relatif `resources/basecolor.png`.
