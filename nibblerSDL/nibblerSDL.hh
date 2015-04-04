//
// nibblerSDL.hh for nibbler in /home/schric_a/Tek2/CPP/cpp_nibbler/nibblerSDL/
//
// Made by Adrien Schricke
// Login   <schric_a@epitech.eu>
//
// Started on  Mon Mar 30 14:46:25 2015 Adrien Schricke
// Last update Wed Apr  1 16:09:10 2015 Adrien Schricke
//

#ifndef         NIBBLERSDL_HH_
# define        NIBBLERSDL_HH_

#include        <SDL/SDL.h>
#include        <unistd.h>

#include        "../IDisplayModule.hh"

class           NibblerSDL : public IDisplayModule
{
public:
    NibblerSDL();
    ~NibblerSDL();

private:
    SDL_Surface     *win;
    int             x;
    int             y;
    int             space;
    int             ox;
    int             oy;
    int             last_x;
    int             last_y;
    int             color_head;
    int             color_body;
    int             color_tail;
    int             color_apple;
    int             color_back;

    //a supprimer
    std::string     name;

public:
    // a supprimer
    std::string const & getName() const;

    int init(int , int );
    void stop();
    t_dir getEvent();
    int refreshScreen();
    int drawGame(int , int, t_type);
    void moveSnake();
    void createWin(int , int );
    int timeToWait(int);

    int printSomething(t_texte , int );
};
#endif
