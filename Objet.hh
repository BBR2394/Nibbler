//
// AObjet.hh for  in 
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Mar 25 16:10:39 2015 Bertrand-Rapello Baptiste
// Last update Wed Mar 25 16:45:03 2015 Bertrand-Rapello Baptiste
//

#ifndef AOBJET_HH_
# define AOBJET_HH_

typedef enum e_type
  {
    FOOD,
    HEAD,
    BODY,
    TAIL
  } t_type;

class Objet
{
public:
  Objet(int, int, t_type);
  ~Objet();
  
private:
  int _posx;
  int _posy;
  t_type _tpe;

public:
  int getPosX() const;
  int getPosY() const;
  t_type getType() const;
  void setPosX(int const &x);
  void setPosY(int const &y);
  void setType(t_type const &tpe);


};

#endif
