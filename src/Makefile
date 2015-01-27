SRC=model/unit.cpp display/window.cpp main.cpp
OBJ=$(SRC:.cpp=.o)
CC=gcc
NAME=ProtoGame
CCFLAGS=-Wall -g

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lSDL2

%.o: %.cpp %.h
	$(CC) -c $< -o $@

clean:
	rm $(OBJ)