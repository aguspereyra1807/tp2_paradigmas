BIN:
	mkdir -p bin/

FLAGS = -std=c++20 -Wall -Wextra -Wpedantic
SOURCES = source/*.cpp examples/main.cpp

main: BIN
	g++ $(FLAGS) $(SOURCES) -o bin/main

run: main
	clear
	./bin/main

run-valgrind: main
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/main

clean:
	rm -rf bin/main
	rm -rf bin