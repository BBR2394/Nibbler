//
// ExceptionNibbler.hh for Nibbler2 in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Mon Mar 16 16:48:56 2015 Bertrand-Rapello Baptiste
// Last update Mon Mar 16 17:17:55 2015 Bertrand-Rapello Baptiste
//

#ifndef EXCEPTIONNIBBLER_HH_
# define EXCEPTIONNIBBLER_HH_

#include <iostream>
#include <exception>

class ExceptLoad : public std::exception
{
public:
  ExceptLoad(const std::string &msg);
  virtual ~ExceptLoad() throw() {};

protected:
  std::string _msg;

public:
  virtual std::string const &getComponent() const throw();
};

#endif
