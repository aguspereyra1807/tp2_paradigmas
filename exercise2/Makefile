BIN:
	mkdir -p bin/

main: BIN
	g++ -std=c++17 -Wall -Wextra -Wpedantic source/*.cpp examples/main.cpp -o bin/main

run: main
	clear
	./bin/main

valgrind: BIN
	g++ -std=c++17 -Wall -Wextra -Wpedantic source/*.cpp examples/main.cpp -o bin/main
	
run-valgrind: valgrind
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/main

clean:
	rm -rf bin/main
	rm -rf bin