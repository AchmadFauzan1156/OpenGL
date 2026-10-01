.PHONY: init build rebuild run clean mlaku

mlaku:
	cmake --build build
	.\build\Debug\OpenGLProject.exe

init:
	cmake -S . -B build

build:
	cmake --build build

rebuild:
	cmake --build build --clean-first

run:
	.\build\Debug\OpenGLProject.exe

clean:
	cmake --build build --target clean