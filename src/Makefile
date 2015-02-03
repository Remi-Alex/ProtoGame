SRC=model/unit.cpp display/window.cpp main.cpp inputs/inputHandler.cpp
OBJ=$(SRC:.cpp=.o)
CC=gcc
NAME=ProtoGame
CCFLAGS=-Wall -g
LIBS=-lSDL2 -lSDL2_image

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.cpp %.h
	$(CC) -c $< -o $@

clean:
	rm $(OBJ) $(NAME)
