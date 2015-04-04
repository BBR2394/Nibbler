//
// LibDeTest.cpp for  in
//
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
//
// Started on  Tue Mar 17 18:38:16 2015 Bertrand-Rapello Baptiste
// Last update Thu Apr  2 08:56:32 2015 Bertrand-Rapello Baptiste
//

#include "LibNCurses.hh"

extern "C" IDisplayModule *getClass()
{
	return (new LibNCurses());
}

LibNCurses::LibNCurses() : _name("LibNCurses")
{
  _cursX = 2;
  _cursY = 15;
  _cursY++;
}

LibNCurses::~LibNCurses()
{

}

/*
** x -> columns
** y -> lines
*/

int LibNCurses::createWin(int x, int y)
{
  _win = newwin(y+2, x+2, 0, 0);

  if (_win == NULL)
    return -1;    
  box(_win, 0, 0);
  _cursX = 2;
  _cursY = y + 2;
  wrefresh(_win);
  refresh();
  return 0;
}

int LibNCurses::init(int x, int y)
{
  //std::cout << "initialisation de la lib de test avec ncurses" << std::endl;
  if (initscr() == NULL)
    return -1;
  getmaxyx(stdscr, _rowMax, _colMax);
  if (x > _colMax || y > _rowMax)
    return (-1);
  //printw("les ligne %d et les colone %d\n", _rowMax, _colMax);
  cbreak(); /*ctrl-C not caught */
  //a remettre
  noecho(); /*dont print the char when press */
  refresh();
  keypad(stdscr, TRUE);
  curs_set(0);
  if (this->createWin(x, y) == -1)
    return -1;

  return 0;
}

void LibNCurses::stop()
{
  echo();
  curs_set(1);
  delwin(_win);
  endwin();
}

std::string const & LibNCurses::getName() const
{
  static int c = 0;
	mvwprintw(_win, 10, 10+c, "bonjour!!");
  c++;
	return (this->_name);
}

t_dir LibNCurses::getEvent()
{
  int ch = 0;

  ch = getch();
  if (ch == 258)
    return UP;
  else if (ch == 260)
    return LEFT;
  else if (ch == 261)
    return RIGHT;
  else if (ch == 259)
    return DOWN;
  else if (ch == 27)
    return END;
  else
   return NOTHING;
}

int LibNCurses::refreshScreen()
{
  werase(_win);
  box(_win, 0, 0);
  wrefresh(_win);
  refresh();
  return 0;
}

int LibNCurses::drawGame(int x, int y, t_type tp)
{
  if (tp == HEAD)
    mvwprintw(_win, y+1, x+1, CHARHEAD);
  else if (tp == BODY)
    mvwprintw(_win, y+1, x+1, CHARBODY);
  else if (tp == TAIL)
    mvwprintw(_win, y+1, x+1, CHARTAIL);
  else if (tp == FOOD)
    mvwprintw(_win, y+1, x+1, "5");
  //_win, y, x, char
  //mvwprintw(_win, 1, 8, "7");
  //mvwprintw(_win, 13, 12, "T");
  wrefresh(_win);
	return (0);
}

int LibNCurses::timeToWait(int sec)
{
  /* en miliseconde */
	timeout(sec);
	return (0);
}

int LibNCurses::printSomething(t_texte msgToDisplay, int scr)
{
  if (msgToDisplay == HI)
  {
    mvwprintw(_win, 1, 1, "press\n");
    mvwprintw(_win, 2, 1, "a touch\n");
    mvwprintw(_win, 3, 1, "to start\n");
    wrefresh(_win);
    return 0;
  }
  else if (msgToDisplay == GO)
  {
    timeout(-1);
    mvwprintw(_win, 1, 1, "GAME\n");
    mvwprintw(_win, 2, 1, "OVER\n");
    wrefresh(_win);
    getch();
    return 0;
  }
  else if (msgToDisplay == SCR)
  {
    mvwprintw(_win, 1, 1, "Score\n  %d", scr);
    wrefresh(_win);
    getch();
    return 0;
  }
  else 
    return 1;
}
