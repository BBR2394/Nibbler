//
// LibDeTest.cpp for  in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue Mar 17 18:38:16 2015 Bertrand-Rapello Baptiste
// Last update Tue Mar 17 18:38:39 2015 Bertrand-Rapello Baptiste
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
	std::cout << "initialisation de la lib de test" << std::endl;
}

void LibDeTest::stop()
{
	std::cout << "arret de la lib de test" << std::endl;
}

std::string const & LibDeTest::getName() const
{
	std::cout << "bonjour !!! de get Name" << std::endl;
}