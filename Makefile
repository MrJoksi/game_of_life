OBJECTS = cellif.o game_of_life.o filutesti.o
CC = gcc
TARGET = game_of_life

all: $(TARGET) clean_o

$(TARGET): $(OBJECTS) 
	$(CC) $(OBJECTS) -lncursesw -o $(TARGET)
cellif.o: cellif.c variables.h
	$(CC) -c cellif.c
game_of_life.o: game_of_life.c variables.h
	$(CC) -c game_of_life.c
filutesti.o: filutesti.c variables.h
	$(CC) -c filutesti.c
clean: clean_o
	rm -f *.exe $(TARGET)
clean_o:
	rm -f *.o  

