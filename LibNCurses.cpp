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
  std::cout << "initialisation de la lib de test avec ncurses" << std::endl;
  initscr();
  getmaxyx(stdscr, _rowMax, _colMax);
  if (x > _colMax || y > _rowMax)
    return (-1);
 //throw ExceptLoad("window to high for the term window");
  std::cout << "les ligne du terminal" << _rowMax << "les colonne " << _colMax << std::endl;
  //printw("les ligne %d et les colone %d\n", _rowMax, _colMax);
  cbreak(); /*ctrl-C not caught */
  //a remettre
  noecho(); /*dont print the char when press */
  refresh();
  keypad(stdscr, TRUE);
  curs_set(0);
  if (this->createWin(x, y) == -1)
    return -1;

  mvwprintw(_win, 1, 1, "press\n");
  mvwprintw(_win, 2, 1, "a touch\n");
  mvwprintw(_win, 3, 1, "to start\n");
  getch();
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
    {
      this->stop();
        //a enlever
      /*exit(0);*/
      return END;
    }
  else
   return NOTHING;

  //ch = getch();
  //refresh();
  //return ch;
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

	timeout(sec/1000);
	return (0);
}

void LibNCurses::printSomething(const std::string & str)
{
  mvwprintw(stdscr, _cursY++, _cursX, str.c_str());
  if (_cursY > _rowMax-2)
    _cursY =  _rowMax - 1;
}
