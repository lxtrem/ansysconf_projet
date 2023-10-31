all: simulateur

simulateur: main.o fonctions.o classes.o
	g++ -o simulateur main.o fonctions.o classes.o

fonctions.o: fonctions.cpp
	g++ -o fonctions.o -c fonctions.cpp

classes.o: classes.cpp
	g++ -o classes.o -c classes.cpp

clean:
	rm -rf *.o simulateur
