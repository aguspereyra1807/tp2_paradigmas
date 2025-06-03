all:
	mkdir -p bin data
	g++ -std=c++17 -Wall source/*.cpp examples/itemB.cpp -o bin/itemB
	g++ -std=c++17 -Wall source/*.cpp examples/itemC.cpp -o bin/itemC
	g++ -std=c++17 -Wall source/*.cpp examples/itemD.cpp -o bin/itemD

b:
	mkdir -p bin data
	g++ -std=c++17 -Wall source/*.cpp examples/itemB.cpp -o bin/itemB
	clear
	./bin/itemB

c:
	mkdir -p bin data
	g++ -std=c++17 -Wall source/*.cpp examples/itemC.cpp -o bin/itemC
	clear
	./bin/itemC

d:
	mkdir -p bin data
	g++ -std=c++17 -Wall source/*.cpp examples/itemD.cpp -o bin/itemD
	clear
	./bin/itemD

d-valgrind:
	mkdir -p bin data
	g++ -std=c++17 -Wall -g source/*.cpp examples/itemD.cpp -o bin/itemD
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/itemD

clean:
	rm -f bin/itemB bin/itemC bin/itemD
	rm -rf bin