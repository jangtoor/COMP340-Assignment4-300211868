CC = gcc
CFLAGS = -Wall -g
SRC = oss.c user.c
OBJ = $(SRC:.c=.o)
TARGET = oss user

all: $(TARGET)

oss: oss.o
    $(CC) -o oss oss.o -lrt

user: user.o
    $(CC) -o user user.o -lrt

clean:
    rm -f *.o $(TARGET)
