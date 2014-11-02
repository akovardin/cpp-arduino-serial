SOURCES = $(wildcard cpp/*.cpp)
OBJ = ${SOURCES:.cpp=.o}
FLAGS = -Wall -lserial -L/usr/lib

serial: ${OBJ}
	g++ $^ -o serial ${FLAGS}

${OBJ}: ${SOURCES}
	g++ -c -std=c++11 $^ -o ${OBJ} ${FLAGS}

clean:
	rm -rf serial
	rm -rf cpp/*.o *.o