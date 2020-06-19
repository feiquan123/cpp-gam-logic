# makefile

all:main.o monster.o weapon.o role.o
	g++ main.o monster.o weapon.o role.o -o main

main.o:main.cpp monster.h role.h
	g++ -o main.o -c main.cpp

monster:monster.h monster.cpp
	g++ -o monster.o -c monster.cpp

weapon:weapon.h weapon.cpp
	g++ -o weapon.o -c weapon.cpp

role:role.h role.cpp
	g++ -o role.o -c role.cpp

.PHONY:clean
clean:
	-rm -rf main.o monster.o weapon.o role.o main