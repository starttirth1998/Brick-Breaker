
OPTS =  -lGL -lglfw -ldl -I"irrKlang-64bit-1.5.0/include" -L"/usr/lib" irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so -pthread

all: sample2D

sample2D: main.o VAO.o create_object.o bucket.o cannon.o bullet.o mirror.o init.o background.o glad.c
	g++ -o sample2D main.o VAO.o create_object.o init.o cannon.o bullet.o bucket.o mirror.o background.o glad.c $(OPTS)

main.o: main.cpp main.h header.h glad.c
	g++ -c main.cpp glad.c $(OPTS)

VAO.o: VAO.cpp VAO.h header.h glad.c
	g++ -c VAO.cpp glad.c -lGL -lglfw -ldl

background.o: background.cpp header.h background.h glad.c
	g++ -c background.cpp glad.c -lGL -lglfw -ldl

mirror.o: mirror.cpp header.h mirror.h glad.c
	g++ -c mirror.cpp glad.c -lGL -lglfw -ldl

bullet.o: bullet.cpp header.h bullet.h glad.c
	g++ -c bullet.cpp glad.c -lGL -lglfw -ldl

cannon.o: cannon.cpp header.h cannon.h glad.c
	g++ -c cannon.cpp glad.c -lGL -lglfw -ldl

bucket.o: bucket.cpp header.h bucket.h glad.c
	g++ -c bucket.cpp glad.c -lGL -lglfw -ldl

create_object.o: create_object.cpp header.h create_object.h glad.c
	g++ -c create_object.cpp glad.c -lGL -lglfw -ldl

init.o: init.cpp header.h init.h glad.c
	g++ -c init.cpp glad.c $(OPTS)

clean:
	rm sample2D

.PHONY: all clean
