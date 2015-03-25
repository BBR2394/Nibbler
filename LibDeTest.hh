//
// LibDeTest.hh for  in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue Mar 17 18:38:42 2015 Bertrand-Rapello Baptiste
// Last update Tue Mar 24 19:15:16 2015 Bertrand-Rapello Baptiste
//

#ifndef LIBDETEST_HH_
# define LIBDETEST_HH_

#include <iostream>
#include <ncurses.h>

#include "IDisplayModule.hh"

enum eDir
  {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };

class LibDeTest : public IDisplayModule
{
public:
  LibDeTest();
  ~LibDeTest();

private:
  std::string _name;
  WINDOW *_win;
  int _cmdPress;
public:
  std::string const & getName() const;
  void init();
  void stop();
  int getEvent();
  int refresh();
  int drawGame();
};

#endif
