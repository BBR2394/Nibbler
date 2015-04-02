//
// LibDeTest.hh for  in
//
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
//
// Started on  Tue Mar 17 18:38:42 2015 Bertrand-Rapello Baptiste
// Last update Thu Apr  2 08:56:10 2015 Bertrand-Rapello Baptiste
//

#ifndef LIBNCURSES_HH_
# define LIBNCURSES_HH_

#include <iostream>
#include <ncurses.h>

#include "IDisplayModule.hh"

#define CHARHEAD "$"
#define CHARBODY "b"
#define CHARTAIL "+"


class LibNCurses : public IDisplayModule
{
public:
  LibNCurses();
  ~LibNCurses();

private:
  std::string _name;
  WINDOW *_win;
  int _rowMax;
  int _colMax;
  int _cmdPress;

  int _cursX, _cursY;
public:
  std::string const & getName() const;
  int init(int , int );
  void stop();
  t_dir getEvent();
  int refreshScreen();
  int drawGame(int , int, t_type);
  void moveSnake();
  int createWin(int , int );
  int timeToWait(int);

  void printSomething(const std::string & str);
};

#endif
