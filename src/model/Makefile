SRC=unit.cpp
OBJ=$(SRC:.cpp=.o)

all: $(OBJ)

%.o: %.cpp %.h
	$(CC) -c $< -o $@