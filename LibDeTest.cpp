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
}

LibDeTest::~LibDeTest()
{

}

void LibDeTest::init()
{
  std::cout << "initialisation de la lib de test avec ncurses" << std::endl;
  initscr();
  cbreak(); /*ctrl-C not caught */
  noecho(); /*dont print the char when press */
  //_win = 
}

void LibDeTest::stop()
{
  std::cout << "arret de la lib de test" << std::endl;
  echo();
  endwin();
}

std::string const & LibDeTest::getName() const
{
	std::cout << "bonjour !!! de get Name" << std::endl;
}

int LibDeTest::getEvent()
{

  std::cout << "je recupere un evenement" << std::endl;
  getch();
  return 4;
}

int LibDeTest::refresh()
{
  std::cout << "je refresh" << std::endl;
  return 3;
}

int LibDeTest::drawGame()
{
  std::cout << "je dessine " << std::endl;
}
