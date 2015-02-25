PACKAGES=display inputs model sound util
SRC= $(wildcard $(addsuffix /*.cpp,$(PACKAGES)))
SRC_GAME= $(SRC) $(wildcard *.cpp) 
SRC_TEST=test/test.cpp $(SRC)
OBJ=$(SRC_GAME:.cpp=.o)
OBJ_TEST=$(SRC_TEST:.cpp=.o)
CC=g++ -std=c++11
NAME=ProtoGame
NAME_TEST=Tests
CCFLAGS=-Wall -g
LIBS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
LIBS_TEST=lib/libUnitTest++.a $(LIBS)

all: test game

game: $(OBJ)
	@echo Compiling game...
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

test: $(OBJ_TEST)
	@echo Linking $(NAME_TEST)...
	@$(CC) -o $(NAME_TEST) $(OBJ_TEST) $(LIBS_TEST)
	@echo Running unit tests...
	@./$(NAME_TEST)

%.o: %.cpp %.h
	$(CC) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJ_TEST) $(NAME) $(NAME_TEST)
