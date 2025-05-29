all:
	mkdir -p bin data
	g++ -std=c++17 -Wall source/*.cpp examples/main.cpp -o bin/pokedex

run: all
	clear
	./bin/pokedex

test:
	mkdir -p bin data
	g++ -std=c++17 -Wall source/*.cpp tests/testShow.cpp -o bin/testShow
	clear
	./bin/testShow

clean:
	rm -f bin/pokedex bin/testShow
	rm -rf bin