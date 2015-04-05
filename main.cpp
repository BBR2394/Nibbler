//
// main.cpp for Nibbler2 in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Mon Mar 16 16:01:28 2015 Bertrand-Rapello Baptiste
// Last update Mon Mar 16 17:19:26 2015 Bertrand-Rapello Baptiste
//

#include <iostream>
#include <sstream>
#include "Nibbler.hh"

int	main(int ac, char **av)
{
  Nibbler nib;
  int x, y;
  
  if (ac <= 3)
  {
    std::cout << "no argument..\n\tusage: \t./nibbler heigth weight lib_nibbler_XXX.so" << std::endl;
    return (-1);
  }

  std::istringstream convert1(av[1]);
  std::istringstream convert2(av[2]);

  if (!(convert1 >> x))
  {
    std::cout << "probleme with the first argument" << std::endl;
    return -1;
  }
  if (!(convert2 >> y))
  {
    std::cout << "probleme with the second argument" << std::endl;
    return -1;
  }

  if (x < 10 || y < 10)
  {
    std::cout << "map too short .." << std::endl;
    return -1;
  }

  try
      {
      nib.prepareTheGame(av[3], x, y);
      nib.playTheGame();
      nib.endGame();
      return 0;
    }
  catch (const ExceptLoad& e)
    {
      
      std::cout << "An exception \"ExceptLoad\" has been thrown :\n     -> " << e.getComponent() << std::endl;
      return -1;
    }

  return 0;
}
