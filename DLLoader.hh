//
// DLLoader.hh for  in /home/baptiste/Documents/TPepitechTek2bis/nibbler/etape4
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Fri Mar 13 14:43:49 2015 Bertrand-Rapello Baptiste
// Last update Wed Mar 18 10:55:17 2015 Bertrand-Rapello Baptiste
//

#ifndef DLLOADER_HH_
# define DLLOADER_HH_

#include <iostream>
#include <dlfcn.h>

#include "IDisplayModule.hh"
#include "ExceptionNibbler.hh"

class DLLoader
{
public:
  DLLoader();
  ~DLLoader();

private:
	IDisplayModule *_obj;

public:
  IDisplayModule *getInstance(char * );
};

#endif
