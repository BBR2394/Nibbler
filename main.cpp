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
#include "Nibbler.hh"

int	main(int ac, char **av)
{
  Nibbler nib;

  if (ac <= 1)
  {
    std::cout << "no argument " << std::endl;
    return (-1);
  }
  try
    {
      nib.loadLibrary(av[1]);
    }
  catch (const ExceptLoad& e)
    {
      std::cout << "An exception \"ExceptLoad\" has been thrown :\n     -> " << e.getComponent() << std::endl;
      return -1;
    }

  return 0;
}
