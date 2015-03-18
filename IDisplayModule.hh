//
// IObjet.hh for  in /home/baptiste/Documents/TPepitechTek2bis/nibbler/etape3
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Thu Mar 12 15:19:51 2015 Bertrand-Rapello Baptiste
// Last update Tue Mar 17 18:29:05 2015 Bertrand-Rapello Baptiste
//

#ifndef IDISPLAYMODULE_HH_
# define IDISPLAYMODULE_HH_

#include <iostream>
#include <string>

class IDisplayModule
{
public:
  virtual ~IDisplayModule() {}
  virtual std::string const & getName() const = 0;
  virtual void init() = 0;
  virtual void stop() = 0;
};

#endif 
