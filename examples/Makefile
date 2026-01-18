all: clean compile run
clean:
	rm -rf eris.o input.o scene.o world.o glad.o color.o
compile:
	gcc -c ../libs/glad/src/glad.c -o glad.o -I../libs/glad/include/
	g++ -c ../src/eris.cpp -o eris.o -I../libs/glad/include/
	g++ -c ../src/core/scene_manager.cpp -o scene.o
	g++ -c ../src/core/renderer.cpp -o renderer.o -I../libs/glad/include/
	g++ -c ../src/game/input_manager.cpp -o input.o
	g++ -c ../src/game/mesh.cpp -o mesh.o -I../libs/glad/include/
	g++ -c ../src/game/material.cpp -o material.o -I../libs/glad/include/
	g++ -c ../src/utils/color.cpp -o color.o
	g++ -c ../src/game/game_object.cpp -o game_object.o

	g++ -c scenes/world.cpp -o world.o -I../src
	g++ -c objects/player.cpp -o player.o -I../src
	
	g++ space.cpp game_object.o input.o eris.o scene.o color.o world.o player.o material.o mesh.o renderer.o glad.o -o space -lSDL3 -ldl -I../src
run:
	./space