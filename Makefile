all: sample2D

sample2D: main.o VAO.o create_object.o bucket.o init.o glad.c
	g++ -o sample2D main.o VAO.o create_object.o init.o bucket.o glad.c -lGL -lglfw -ldl

main.o: main.cpp main.h header.h glad.c
	g++ -c main.cpp glad.c -lGL -lglfw -ldl

VAO.o: VAO.cpp VAO.h header.h glad.c
	g++ -c VAO.cpp glad.c -lGL -lglfw -ldl

bucket.o: bucket.cpp header.h bucket.h glad.c
	g++ -c bucket.cpp glad.c -lGL -lglfw -ldl

create_object.o: create_object.cpp header.h create_object.h glad.c
	g++ -c create_object.cpp glad.c -lGL -lglfw -ldl

init.o: init.cpp header.h init.h glad.c
	g++ -c init.cpp glad.c -lGL -lglfw -ldl

clean:
	rm sample2D

.PHONY: all clean
