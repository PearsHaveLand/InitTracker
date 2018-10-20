GXX=g++
FLAGS=-c -g

character.o: character.cpp character.h
	$(GXX) $(FLAGS) character.cpp -c

tracker: tracker.cpp
	$(GXX) $(FLAGS) character.o tracker.cpp -o tracker

run: tracker
	./tracker
