# Michael Moses, 1.05.2024r.
# Variable names
CC = g++
CFLAGS = -Wall

PROJECT_NAME = project

# Run all the files one by one
all: main algorytmy print memory time file project

# Make all the files here into .o one by one
main: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

algorytmy: algorytmy.cpp
	$(CC) $(CFLAGS) -c algorytmy.cpp -o algorytmy.o

print: print.cpp
	$(CC) $(CFLAGS) -c print.cpp -o print.o

memory: memoryManager.cpp
	$(CC) $(CFLAGS) -c memoryManager.cpp -o memory.o

time: timeManager.cpp
	$(CC) $(CFLAGS) -c timeManager.cpp -o time.o

file: fileManager.cpp	
	$(CC) $(CFLAGS) -c fileManager.cpp -o file.o



# Combine all the files here into one project
project: main.o 
	$(CC) $(CFLAGS) main.o algorytmy.o print.o memory.o time.o file.o -o $(PROJECT_NAME)

# Run the project
run: 
	./$(PROJECT_NAME)

# Clean all the not needed files
clear:
	rm *.o $(PROJECT_NAME)
