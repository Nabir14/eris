all: clean compile run
clean:
	rm -rf space eris.o input.o scene.o
compile:
	g++ -c ../src/eris.cpp -o eris.o -lSDL3
	g++ -c ../src/core/scene_manager.cpp -o scene.o -lSDL3
	g++ -c ../src/game/input_manager.cpp -o input.o -lSDL3
	g++ -c ../src/core/script_server.cpp -o script_server.o -llua -lm
	g++ space.cpp input.o eris.o scene.o script_server.o -o space -lSDL3 -llua -lm
run:
	./space