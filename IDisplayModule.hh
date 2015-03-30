//
// IObjet.hh for  in /home/baptiste/Documents/TPepitechTek2bis/nibbler/etape3
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Thu Mar 12 15:19:51 2015 Bertrand-Rapello Baptiste
// Last update Tue Mar 24 19:14:01 2015 Bertrand-Rapello Baptiste
//

#ifndef IDISPLAYMODULE_HH_
# define IDISPLAYMODULE_HH_

#include <iostream>
#include <string>

#include "Objet.hh"

typedef enum e_dir
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
  NOTHING,
	END
} t_dir;

class IDisplayModule
{
public:
  virtual ~IDisplayModule() {}
  virtual std::string const & getName() const = 0;
  virtual void init(int, int) = 0;
  virtual void stop() = 0;
  virtual t_dir getEvent() = 0;
  virtual int refreshScreen() = 0;
  virtual int drawGame(int, int, t_type) = 0;
  virtual int timeToWait(int) = 0;
};

#endif 
