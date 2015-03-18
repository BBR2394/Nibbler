//
// LibDeTest.hh for  in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue Mar 17 18:38:42 2015 Bertrand-Rapello Baptiste
// Last update Tue Mar 17 18:40:59 2015 Bertrand-Rapello Baptiste
//

#ifndef LIBDETEST_HH_
# define LIBDETEST_HH_

#include <iostream>

#include "IDisplayModule.hh"

class LibDeTest : public IDisplayModule
{
public:
  LibDeTest();
  ~LibDeTest();

private:
  std::string _name;

public:
  std::string const & getName() const;
  void init();
  void stop();
};

#endif
