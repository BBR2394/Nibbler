//
// AObjet.cpp for  in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Mar 25 16:39:16 2015 Bertrand-Rapello Baptiste
// Last update Wed Mar 25 16:39:50 2015 Bertrand-Rapello Baptiste
//

#include "Objet.hh"

Objet::Objet(int x, int y, t_type tpe) : _posx(x), _posy(y), _tpe(tpe)
{

}

Objet::~Objet()
{

}

int Objet::getPosX() const
{
	return _posx;
}

int Objet::getPosY() const
{
	return _posy;
}

t_type Objet::getType() const
{
	return _tpe;
}

void Objet::setPosX(int const &x)
{
	_posx = x;
}

void Objet::setPosY(int const &y)
{
	_posy = y;
}

void Objet::setType(t_type const &tpe)
{
	_tpe = tpe;
}