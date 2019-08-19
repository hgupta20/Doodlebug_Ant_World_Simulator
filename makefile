hgupta20Proj7:  Island.o Creature.o doodleBug.o ant.o GridDisplay.o hgupta20Proj7.o
	g++ -o hgupta20Proj7 hgupta20Proj7.o Island.o Creature.o doodleBug.o ant.o GridDisplay.o

hgupta20Proj7.o:  hgupta20Proj7.cpp
	g++ -std=c++11 -c hgupta20Proj7.cpp

GridDisplay.o: GridDisplay.cpp GridDisplay.h
	g++ -std=c++11 -c GridDisplay.cpp

ant.o: ant.cpp ant.h Island.h
	g++ -std=c++11 -c ant.cpp

doodleBug.o: doodleBug.cpp doodleBug.h Island.h
	g++ -std=c++11 -c doodleBug.cpp

Creature.o: Creature.cpp Creature.h Island.h
	g++ -std=c++11 -c Creature.cpp

Island.o: Island.cpp Island.h
	g++ -std=c++11 -c Island.cpp

clean:
	rm hgupta20Proj7 Island.o Creature.o doodleBug.o ant.o GridDisplay.o
