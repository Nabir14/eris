all: clean compile run
clean:
	rm -rf space eris.o input.o scene.o world.o
compile:
	g++ -c ../src/eris.cpp -o eris.o
	g++ -c ../src/core/scene_manager.cpp -o scene.o
	g++ -c ../src/game/input_manager.cpp -o input.o
	g++ -c scenes/world.cpp -o world.o
	g++ space.cpp input.o eris.o scene.o world.o -o space -lSDL3
run:
	./space