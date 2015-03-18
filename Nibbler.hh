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

#include "IDisplayModule.hh"
#include "DLLoader.hh"
#include "ExceptionNibbler.hh"

class Nibbler
{
public:
  Nibbler();
  ~Nibbler();

private:
	IDisplayModule *_lib;

public:
 	void loadLibrary(char *name);
	void playTheGame();
};

#endif