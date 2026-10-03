# Template Proyek OpenGL

Template sederhana C++ OpenGL yang menggunakan:

* C++17
* CMake
* GLFW 3.5.1
* GLAD 2.0.8
* OpenGL 4.6 Core
* MSVC

## Kebutuhan

Pasang dulu tool berikut:

1. **Visual Studio** dengan workload "Desktop development with C++" (MSVC)
2. **CMake** versi 3.25 atau lebih baru
3. **Git**
4. **Python** 3
5. **Make** (untuk menjalankan perintah `make` di bawah)

GLFW dan GLAD diunduh otomatis oleh CMake. `stb_image` sudah tersedia di folder `include/`.

### Kebutuhan Python

GLAD 2 membuat loader OpenGL saat proses build menggunakan Python, jadi paket Python yang tercantum di `requirement.txt` harus dipasang sebelum menjalankan `make init`.

Pasang dengan:

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

Clone proyek lalu pasang kebutuhan Python:

```bash
git clone https://github.com/AchmadFauzan1156/OpenGL.git
cd OpenGL
python -m pip install -r requirement.txt
```

Kemudian konfigurasi proyek:

```bash
make init
```

Perintah ini mengonfigurasi CMake serta mengunduh GLFW dan GLAD secara otomatis.

## Build & Jalankan

Build:

```bash
make build
```

Jalankan:

```bash
make run
```

Build dan jalankan sekaligus:

```bash
make mlaku
```

Atau build ulang dari awal:

```bash
make rebuild
```

Bersihkan hasil build:

```bash
make clean
```

## Perintah Make

| Perintah       | Keterangan                    |
| -------------- | ----------------------------- |
| `make init`    | Inisialisasi CMake            |
| `make build`   | Build proyek                  |
| `make rebuild` | Bersihkan lalu build ulang    |
| `make run`     | Jalankan aplikasi             |
| `make mlaku`   | Build lalu jalankan           |
| `make clean`   | Bersihkan hasil build         |

## Struktur Proyek

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

Jalankan aplikasi dari root proyek (seperti yang dilakukan `make run`), karena tekstur dimuat dari path relatif `resources/basecolor.png`.
