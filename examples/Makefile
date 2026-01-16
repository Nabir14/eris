all: clean compile run
clean:
	rm -rf eris.o input.o scene.o world.o glad.o color.o
compile:
	gcc -c ../libs/glad/src/glad.c -o glad.o -I../libs/glad/include/
	g++ -c ../src/eris.cpp -o eris.o -I../libs/glad/include/
	g++ -c ../src/core/scene_manager.cpp -o scene.o -I../libs/glad/include/
	g++ -c ../src/game/input_manager.cpp -o input.o
	g++ -c ../src/utils/color.cpp -o color.o
	g++ -c scenes/world.cpp -o world.o -I../src
	g++ space.cpp input.o eris.o scene.o color.o world.o glad.o -o space -lSDL3 -ldl -I../src
run:
	./space