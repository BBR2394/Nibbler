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

void Nibbler::callDraw()
{
	std::list<Objet*>::iterator it = _snake.begin();
	std::list<Objet*>::iterator itObj = _food.begin();
	Objet *temp;

	while (it != _snake.end())
	{
		temp = *it;
		_lib->drawGame(temp->getPosX(), temp->getPosY(), temp->getType());
		it++;
	}
	while (itObj != _food.end())
	{
		temp = *itObj;
		_lib->drawGame(temp->getPosX(), temp->getPosY(), temp->getType());
		itObj++;
	}
}

void Nibbler::moveSnake(t_dir dir)
{
	std::list<Objet*>::iterator it = _snake.end();
	Objet *tmp1;
	Objet *tmp2;

	--it;
	tmp1 = *it;
	while (it != _snake.begin())
	{
		--it;
		tmp2 = *it;
		tmp1->setPosX(tmp2->getPosX());
		tmp1->setPosY(tmp2->getPosY());
		tmp1 = tmp2;
	}
	if (dir == UP)
		tmp1->setPosY(tmp1->getPosY() + 1);
	else if (dir == RIGHT)
		tmp1->setPosX(tmp1->getPosX() + 1);
	else if (dir == LEFT)
		tmp1->setPosX(tmp1->getPosX() - 1);
	else if (dir == DOWN)
		tmp1->setPosY(tmp1->getPosY() - 1);
	
}

void Nibbler::playTheGame()
{
 	int	c = 0;
	static t_dir staticRtr = RIGHT;
	t_dir lastRtr;

  while (c < 16)
    {
    	this->callDraw();
      	lastRtr = _lib->getEvent();
		c++;
		if (lastRtr == NOTHING)
			lastRtr = staticRtr;
		else
			staticRtr = lastRtr;
		this->moveSnake(lastRtr);
		_lib->timeToWait(500);
      	_lib->refreshScreen();
    }
	_lib->stop();
}

void	Nibbler::loadLibrary(char *name)
{
	DLLoader *loader;

	loader = new DLLoader;
	_lib = loader->getInstance(name);
	if (_lib == NULL)
  		throw ExceptLoad("problem when Loading Shared Library");
	_lib->init(_x, _y);	
}

void	Nibbler::prepareTheGame(char *name, int x, int y)
{
	_x = x;
	_y = y;
	this->loadLibrary(name);

	_snake.push_front(new Objet(x/2, y/2, HEAD));
	_snake.push_back(new Objet((x/2) - 1, y/2, BODY));
	_snake.push_back(new Objet((x/2) - 2, y/2, BODY));
	_snake.push_back(new Objet((x/2) - 3, y/2, TAIL));
	_food.push_front(new Objet(3, 3, FOOD));
}

void Nibbler::endGame()
{
	while (!_snake.empty())
    	_snake.pop_front();
    _food.pop_front();
}