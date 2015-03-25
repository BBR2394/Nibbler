//
// Nibbler.cpp for  Nibbler2 in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Mon Mar 16 16:00:57 2015 Bertrand-Rapello Baptiste
// Last update Thu Mar 19 15:31:50 2015 Bertrand-Rapello Baptiste
//

#include "Nibbler.hh"

Nibbler::Nibbler()
{

}

Nibbler::~Nibbler()
{

}

void Nibbler::playTheGame()
{
  int	c = 0;

  while (c < 5)
    {
      _lib->getEvent();
      _lib->refresh();
      c++;
    }
	
}

void	Nibbler::loadLibrary(char *name)
{
	DLLoader *loader;

	loader = new DLLoader;
	_lib = loader->getInstance(name);
	if (_lib == NULL)
  		throw ExceptLoad("problem when Loading Shared Library");
	_lib->init();
	_lib->getName();

	this->playTheGame();

	_lib->stop();
}
