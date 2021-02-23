all:	funcoes_classes.o main.o
	g++ -o main funcoes_classes.o main.o

funcoes_classes.o:	funcoes_classes.cpp funcoes_classes.hpp
	g++ -c funcoes_classes.cpp

main.o : main.cpp funcoes_classes.hpp
	g++ -c main.cpp

clean:
	rm -rf *.o
	
rodar:
	./main
