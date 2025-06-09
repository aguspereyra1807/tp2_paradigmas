BIN:
	mkdir -p bin data

FLAGS = -std=c++17 -Wall -Wextra -Wpedantic

b: BIN
	g++ $(FLAGS) source/*.cpp examples/itemB.cpp -o bin/itemB

run-b: b
	clear
	./bin/itemB

c: BIN
	g++ $(FLAGS) source/*.cpp examples/itemC.cpp -o bin/itemC

run-c: c
	clear
	./bin/itemC

d: BIN
	g++ $(FLAGS) source/*.cpp examples/itemD.cpp -o bin/itemD

run-d: d
	clear
	./bin/itemD

d-valgrind: BIN
	g++ $(FLAGS) -g source/*.cpp examples/itemD.cpp -o bin/itemD

run-d-valgrind: d-valgrind
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/itemD

all: b c d

run-all: run-b run-c run-d

clean:
	rm -f bin/itemB bin/itemC bin/itemD
	rm -rf data
	rm -rf bin