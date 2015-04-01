

SRC =	main.cpp \
	Nibbler.cpp \
	ExceptionNibbler.cpp \
	DLLoader.cpp \
	Objet.cpp

NAME = nibbler

SRCLIBTEST = LibDeTest.cpp

SRCLIBSDL = nibblerSDL/nibblerSDL.cpp

NAMELIBTEST = lib_de_test.so

NAMELIBSDL = lib_sdl.so

OBJ = $(SRC:.cpp=.o)

OBJLIB = $(SRCLIBDETEST:.cpp=.o)
OBJSDL = $(SRCLIBSDL:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) -ldl
	g++ -o $(NAMELIBTEST) $(SRCLIBTEST) -shared -fPIC -ldl -lncurses
	g++ -o $(NAMELIBSDL) $(SRCLIBSDL) -shared -fPIC -ldl -lSDL

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAMELIBTEST)
	rm -rf $(NAMELIBSDL)

re: fclean all

.PHONY: all clean fclean re
