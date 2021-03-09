all:	funcoes_classes.o main.o sobrecarregados.o
	g++ -o main funcoes_classes.o main.o sobrecarregados.o

funcoes_classes.o:	funcoes_classes.cpp funcoes_classes.hpp
	g++ -c funcoes_classes.cpp

sobrecarregados.o:	sobrecarregados.cpp funcoes_classes.hpp
	g++ -c sobrecarregados.cpp

main.o : main.cpp funcoes_classes.hpp
	g++ -c main.cpp

clean:
	rm -rf *.o
	
rodar:
	./main
