BIN:
	mkdir -p bin/

run: BIN
	g++ -std=c++17 -Wall source/*.cpp examples/main.cpp -o bin/main
	./bin/main

valgrind: BIN
	g++ -std=c++17 -Wall source/*.cpp examples/main.cpp -o bin/main
	valgrind ./bin/main