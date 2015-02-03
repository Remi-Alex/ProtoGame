SRC=model/unit.cpp display/window.cpp main.cpp
SRC_TEST=test/Test.cpp
OBJ=$(SRC:.cpp=.o)
OBJ_TEST=$(SRC_TEST:.cpp=.o)
CC=gcc
CC_TEST=g++
NAME=ProtoGame
NAME_TEST=Tests
CCFLAGS=-Wall -g
LIBS=-lSDL2 -lSDL2_image
LIBS_TEST=lib/libUnitTest++.a

all: test game

game: $(OBJ)
	@echo Compiling game...
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

test: $(LIBS_TEST) $(OBJ_TEST)
	@echo Linking $(NAME_TEST)...
	@$(CC_TEST) -o $(NAME_TEST) $(OBJ_TEST) $(LIBS_TEST)
	@echo Running unit tests...
	@./$(NAME_TEST)

%.o: %.cpp %.h
	$(CC) -c $< -o $@

clean:
	rm $(OBJ) $(OBJ_TEST) $(NAME) $(NAME_TEST)
