GPP = g++
CFLAGS = -c 
OFLAGS = -o
GFLAGS = -g

alt: my_prog

CVector.o input_values.o main.o: CVector.cpp input_values.cpp main.cpp autotests.cpp
	$(GPP) $(CFLAGS) *.cpp

my_prog: CVector.o input_values.o main.o autotests.o
	$(GPP) *.o $(OFLAGS) my_prog

clear: 
	rm -rf *.o my_prog
