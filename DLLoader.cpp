//
// DLLoader.cpp for  in /home/baptiste/Documents/TPepitechTek2bis/nibbler/etape4
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Fri Mar 13 14:46:31 2015 Bertrand-Rapello Baptiste
// Last update Fri Mar 13 14:46:41 2015 Bertrand-Rapello Baptiste
//

#include <iostream>
#include <dlfcn.h>

#include "DLLoader.hh"

DLLoader::DLLoader()
{
}

DLLoader::~DLLoader()
{
}

IDisplayModule *DLLoader::getInstance(char *name)
{
	void *lib;
	IDisplayModule *(*fn_lib)();
	char *rtr = NULL;

	fn_lib = NULL;
	lib = dlopen(name, RTLD_LAZY | RTLD_LOCAL);
	if (lib == NULL)
		throw ExceptLoad("impossible to open the shared library");
	fn_lib = reinterpret_cast<IDisplayModule *(*)()>(dlsym(lib, "getClass"));
	rtr = dlerror();
	if (fn_lib == NULL)
		throw ExceptLoad("problem when Loading Shared Library n°2");
	_obj = fn_lib();
	return _obj;
}

