SRC=model/unit.cpp model/player.cpp display/window.cpp main.cpp inputs/inputHandler.cpp
SRC_TEST=test/test.cpp
OBJ=$(SRC:.cpp=.o)
OBJ_TEST=$(SRC_TEST:.cpp=.o)
CC=g++
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
	@$(CC) -o $(NAME_TEST) $(OBJ_TEST) $(LIBS_TEST)
	@echo Running unit tests...
	@./$(NAME_TEST)

%.o: %.cpp %.h
	$(CC) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJ_TEST) $(NAME) $(NAME_TEST)
