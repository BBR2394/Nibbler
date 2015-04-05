//
// ExceptionNibbler.cpp for Nibbler2 in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Mon Mar 16 17:14:13 2015 Bertrand-Rapello Baptiste
// Last update Mon Mar 16 17:19:55 2015 Bertrand-Rapello Baptiste
//

#include "ExceptionNibbler.hh"

ExceptLoad::ExceptLoad(const std::string &msg): _msg(msg)
{
}

std::string const &ExceptLoad::getComponent() const throw()
{
  return _msg;
}
