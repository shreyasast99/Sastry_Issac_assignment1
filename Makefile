CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c -std=c++14 $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile: main.out

main.out: main.o Instructor.o Student.o
	$(CC) $(LFLAGS) -o main.out Instructor.o Student.o main.o 

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp

Instructor.o: Instructor.cpp Instructor.h
	$(CC) $(CFLAGS) Instructor.cpp

Student.o: Student.cpp Student.h
	$(CC) $(CFLAGS) Student.cpp

run: main.out
	./main.out instructors.txt students.txt

clean:
	rm *.o main.out

