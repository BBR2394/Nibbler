//
// Nibbler.hh for  Nibbler2 in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Mon Mar 16 15:58:39 2015 Bertrand-Rapello Baptiste
// Last update Mon Mar 16 17:19:37 2015 Bertrand-Rapello Baptiste
//

#ifndef NIBBLER_HH_
# define NIBBLER_HH_

#include <iostream>
#include <list>
#include "IDisplayModule.hh"
#include "DLLoader.hh"
#include "ExceptionNibbler.hh"

class Nibbler
{
public:
  Nibbler();
  ~Nibbler();

private:
	int _pts;
	int _eaten;
	IDisplayModule *_lib;
	std::list<Objet*> _snake;
	std::list<Objet*> _food;
	int _x;
	int _y;

	int tmp1;
	int tmp2;

public:
 	void loadLibrary(char *name);
	int playTheGame();
	void callDraw();
	void prepareTheGame(char *, int , int );
	int moveSnake(t_dir);
	void endGame();
	int checkColWithFood();
	int checkColWithHimself()
;};

#endif
