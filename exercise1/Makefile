BIN:
	mkdir -p bin data

b: BIN
	g++ -std=c++17 -Wall -Wextra -Wpedantic source/*.cpp examples/itemB.cpp -o bin/itemB

run-b: b
	clear
	./bin/itemB

c: BIN
	g++ -std=c++17 -Wall -Wextra -Wpedantic source/*.cpp examples/itemC.cpp -o bin/itemC

run-c: c
	clear
	./bin/itemC

d: BIN
	g++ -std=c++17 -Wall -Wextra -Wpedantic source/*.cpp examples/itemD.cpp -o bin/itemD

run-d: d
	clear
	./bin/itemD

d-valgrind: BIN
	g++ -std=c++17 -Wall -Wextra -Wpedantic -g source/*.cpp examples/itemD.cpp -o bin/itemD

run-d-valgrind: d-valgrind
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/itemD

all: b c d

run-all: run-b run-c run-d

clean:
	rm -f bin/itemB bin/itemC bin/itemD
	rm -rf data
	rm -rf bin