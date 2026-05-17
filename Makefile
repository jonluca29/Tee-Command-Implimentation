CC = gcc
CFLAGS = -Wall -Wextra
 
TARGET = myTee
SRC = myTee.c
 
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
 
clean:
	rm -f $(TARGET)
 

