all: TemplatedMy_matrix.o main.o
	c++ -std=c++11 TemplatedMy_matrix.o main.o -o main
TemplatedMy_matrix.o: TemplatedMy_matrix.cpp TemplatedMy_matrix.h
	c++ -std=c++11 -c -g TemplatedMy_matrix.cpp
main.o: main.cpp TemplatedMy_matrix.h
	c++ -std=c++11 -c -g main.cpp
clean:
	rm *.o main
