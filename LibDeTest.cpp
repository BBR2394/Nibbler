//
// LibDeTest.cpp for  in
//
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
//
// Started on  Tue Mar 17 18:38:16 2015 Bertrand-Rapello Baptiste
// Last update Tue Mar 24 19:14:45 2015 Bertrand-Rapello Baptiste
//

#include "LibDeTest.hh"

extern "C" IDisplayModule *getClass()
{
	return (new LibDeTest());
}

LibDeTest::LibDeTest() : _name("LibDeTest")
{
  _cursX = 2;
  _cursY = 15;
  _cursY++;
}

LibDeTest::~LibDeTest()
{

}

/*
** x -> columns
** y -> lines
*/

void LibDeTest::createWin(int x, int y)
{
  _win = newwin(y, x, 0, 0);
  if (_win == NULL)
    throw ("problem when create the window");
  box(_win, 0, 0);
  wrefresh(_win);
  refresh();
}

void LibDeTest::init(int x, int y)
{
  std::cout << "initialisation de la lib de test avec ncurses" << std::endl;
  initscr();
  getmaxyx(stdscr, _rowMax, _colMax);
  std::cout << "les ligne du terminal" << _rowMax << "les colonne " << _colMax << std::endl;
  //printw("les ligne %d et les colone %d\n", _rowMax, _colMax);
  cbreak(); /*ctrl-C not caught */
  //a remettre
  noecho(); /*dont print the char when press */
  refresh();
  keypad(stdscr, TRUE);
  this->createWin(x, y);
  mvwprintw(stdscr, _cursY, _cursX, "BONJOUR !!");
  getch();
}

void LibDeTest::stop()
{
  //echo();
  delwin(_win);
  endwin();
}

std::string const & LibDeTest::getName() const
{
  static int c = 0;
	mvwprintw(_win, 10, 10+c, "bonjour!!");
  c++;
	return (this->_name);
}

t_dir LibDeTest::getEvent()
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

int LibDeTest::refreshScreen()
{
  werase(_win);
  box(_win, 0, 0);
  wrefresh(_win);
  refresh();
  return 0;
}

int LibDeTest::drawGame(int x, int y, t_type tp)
{
  if (tp == HEAD)
    mvwprintw(_win, y+1, x+1, CHARHEAD);
  else if (tp == BODY)
    mvwprintw(_win, y+1, x+1, CHARBODY);
  else if (tp == TAIL)
    mvwprintw(_win, y+1, x+1, CHARTAIL);
  else
    mvwprintw(_win, y+1, x+1, "5");
  //_win, y, x, char
  //mvwprintw(_win, 1, 8, "7");
  //mvwprintw(_win, 13, 12, "T");
  wrefresh(_win);
	return (0);
}

int LibDeTest::timeToWait(int sec)
{

	timeout(sec);
	return (0);
}

void LibDeTest::printSomething(const std::string & str)
{
  mvwprintw(stdscr, _cursY++, _cursX, str.c_str());
}
