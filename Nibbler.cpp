//
// Nibbler.cpp for  Nibbler2 in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Mon Mar 16 16:00:57 2015 Bertrand-Rapello Baptiste
// Last update Sun Apr  5 11:26:04 2015 Bertrand-Rapello Baptiste
//

#include <cstdlib>
#include <iostream>
# include	<fstream>
#include <sstream>
#include "Nibbler.hh"

Nibbler::Nibbler() : _pts(0), _eaten(0), _score(0), _timeOut(100), _actualDir(RIGHT)
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

int Nibbler::checkColWithFoodBis(int x, int y)
{
  std::list<Objet*>::iterator itSnake = _snake.begin();
  Objet *tmp;
  
  itSnake++;
  while (itSnake != _snake.end())
    {
      tmp = *itSnake;
      if (tmp->getPosX() == x && tmp->getPosY() == y)
	return 1;
      else
	itSnake++;
    }
  return 0;
}

int Nibbler::checkColWithFood()
{
  int newX, newY;
  std::list<Objet*>::iterator itFood = _food.begin();
  Objet *tmp;
  std::string str;
  
  while (itFood != _food.end() && !_food.empty())
    {
      tmp = *itFood;
      if (tmp->getPosX() == _snake.front()->getPosX() && tmp->getPosY() == _snake.front()->getPosY())
	{
	  _eaten++;
	  _food.erase(itFood);
	  do
	    {
	      newX = (rand() % (_x-2)) ;
	      newY = (rand() % (_y-2)) ;
	    } while (checkColWithFoodBis(newX, newY) == 1);
	  tmp1 = newX;
	  tmp2 = newY;
	  _food.push_front(new Objet(newX, newY, FOOD));
	  _score += 1;
	  return 1;
	}
      else
	itFood++;
    }
  return 0;
}

int Nibbler::checkColWithHimself()
{
  std::list<Objet*>::iterator itSnake = _snake.begin();
  Objet *head;
  Objet *tmp;
  
  itSnake++;
  head = *itSnake;
  itSnake++;
  while (itSnake != _snake.end())
    {
      tmp = *itSnake;
      if (tmp->getPosX() == head->getPosX() && tmp->getPosY() == head->getPosY())
	return 1;
      else
	itSnake++;
    }
  return 0;
}

int Nibbler::moveSnake(t_dir dir)
{
  std::list<Objet*>::iterator it = _snake.end();
  Objet *tmp1;
  Objet *tmp2;
  std::string str;
  
  --it;
  tmp1 = *it;
  while (it != _snake.begin())
    {
      --it;
      tmp2 = *it;
      if (_eaten == 1)
	{
	  _snake.push_back(new Objet(tmp1->getPosX(), tmp1->getPosY(), TAIL));
	  tmp1->setType(BODY);
	  _eaten = 0;
	}
      tmp1->setPosX(tmp2->getPosX());
      tmp1->setPosY(tmp2->getPosY());
      tmp1 = tmp2;
    }
  this->checkColWithFood();
  if (dir == UP)
    tmp1->setPosY(tmp1->getPosY() + 1);
  else if (dir == RIGHT)
    tmp1->setPosX(tmp1->getPosX() + 1);
  else if (dir == LEFT)
    tmp1->setPosX(tmp1->getPosX() - 1);
  else if (dir == DOWN)
    tmp1->setPosY(tmp1->getPosY() - 1);
  
  if (this->checkColWithHimself() == 1)
    return 1;
  
  if (tmp1->getPosY() > _y-1 || tmp1->getPosY() < 0)
    return 1;
  else if (tmp1->getPosX() > _x-1 || tmp1->getPosX() < 0)
    return 1;
  
  return (0);
  
}

t_dir Nibbler::changeDir(t_dir direction, t_dir touch)
{
  if (touch == LEFT)
    {
      switch (direction)
	{
	case UP : 
	  _actualDir = RIGHT;
	  break;
	case RIGHT:
	  _actualDir = DOWN;
	  break;
	case DOWN:
	  _actualDir = LEFT;
	  break;
	case LEFT:
	  _actualDir = UP;
	  break;
	default:
	  break;
	}
    }
  else if (touch == RIGHT)
    {
      switch (direction)
	{
	case UP : 
	  _actualDir = LEFT;
	  break;
	case LEFT :
	  _actualDir = DOWN;
	  break;
	case DOWN : 
	  _actualDir = RIGHT;
	  break;
	case RIGHT :
	  _actualDir = UP;
	  break;
	default : 
	  break;
	}
    }
  
}

int Nibbler::playTheGame()
{
  t_dir lastRtr;
  int rtrMove;
  
  rtrMove = 0;
  if (_lib->printSomething(HI, 0) == 1)
    std::cout << "Game Start : Press a touch to start" << std::endl;
  while (rtrMove != 1)
    {
      this->callDraw();
      lastRtr = _lib->getEvent();
      
      if (lastRtr == END)
	rtrMove = 1;
      else
      	{
	  this->changeDir(_actualDir, lastRtr);
	  rtrMove = this->moveSnake(_actualDir);
	  /* 100 miliseconde c'est bien */
	  _lib->timeToWait(_timeOut-(_score*3));
	  _lib->refreshScreen();
      	}
    }
  if (_lib->printSomething(GO, 0) == 1)
    std::cout << "GAME OVER" << std::endl;
  _lib->refreshScreen();
  if (_lib->printSomething(SCR, _score) == 1)
    std::cout << "Score : " << _score << std::endl;
  _lib->stop();
}

void	Nibbler::loadLibrary(char *name)
{
  DLLoader *loader;
  
  loader = new DLLoader;
  _lib = loader->getInstance(name);
  if (_lib == NULL)
    throw ExceptLoad("problem when Loading Shared Library");
  if (_lib->init(_x, _y) == -1)
    {
      _lib->stop();
      throw ExceptLoad("problem when I initialize the Shared Library");;	
    }
}

void	Nibbler::prepareTheGame(char *name, int x, int y)
{
  _x = x;
  _y = y;
  this->loadLibrary(name);
  srand(time(NULL));
  _snake.push_front(new Objet(x/2, y/2, HEAD));
  _snake.push_back(new Objet((x/2) - 1, y/2, BODY));
  _snake.push_back(new Objet((x/2) - 2, y/2, BODY));
  _snake.push_back(new Objet((x/2) - 3, y/2, TAIL));
  _food.push_front(new Objet(x/3, y/3, FOOD));
}

void Nibbler::endGame()
{
  while (!_snake.empty())
    _snake.pop_front();
  _food.pop_front();
}
