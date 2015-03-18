

SRC =	main.cpp \
	Nibbler.cpp \
	ExceptionNibbler.cpp \
	DLLoader.cpp 

NAME = nibbler

SRCLIBTEST = LibDeTest.cpp

NAMELIBTEST = lib_de_test.so

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) -ldl
	g++ -o $(NAMELIBTEST) $(SRCLIBTEST) -shared -fPIC -ldl 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAMELIBTEST)

re: fclean all