CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = ministats
OBJ = main.o stats.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lm

main.o: main.c stats.h
	$(CC) $(CFLAGS) -c main.c

stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.c

clean:
	rm -f $(OBJ) $(TARGET)
