SRC=window.cpp
OBJ=$(SRC:.cpp=.o)

all: $(OBJ)

%.o: %.cpp %.h
	$(CC) -c $< -o $@