all: clean compile run
clean:
	rm -rf space
compile:
	g++ -c ../src/eris.cpp -o eris.o -lSDL3
	g++ -c ../src/core/scene.cpp -o scene.o -lSDL3
	g++ space.cpp eris.o scene.o -o space -lSDL3
run:
	./space