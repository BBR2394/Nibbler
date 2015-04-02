##
## Makefile for  in /home/schric_a/Tek2/CPP/cpp_nibbler/
##
## Made by Adrien Schricke
## Login   <schric_a@epitech.eu>
##
## Started on  Wed Apr  1 16:41:07 2015 Adrien Schricke
##Last update Thu Apr  2 08:54:04 2015 Bertrand-Rapello Baptiste
##

SRC =	main.cpp \
	Nibbler.cpp \
	ExceptionNibbler.cpp \
	DLLoader.cpp \
	Objet.cpp

NAME = nibbler

SRCLIBNCURSES = LibNCurses.cpp

SRCLIBSDL = nibblerSDL/nibblerSDL.cpp

NAMELIBNCURSES = lib_ncurses.so

NAMELIBSDL = lib_sdl.so

CFLAGS = -W -Wall -Wextra

OBJ = $(SRC:.cpp=.o)

OBJLIB = $(SRCLIBNCURSES:.cpp=.o)
OBJSDL = $(SRCLIBSDL:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS) -ldl
	g++ -o $(NAMELIBNCURSES) $(SRCLIBNCURSES) $(CFLAGS) -shared -fPIC -ldl -lncurses
	g++ -o $(NAMELIBSDL) $(SRCLIBSDL) $(CFLAGS) -shared -fPIC -ldl -lSDL

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAMELIBNCURSES)
	rm -rf $(NAMELIBSDL)

re: fclean all

.PHONY: all clean fclean re
