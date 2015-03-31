//
// nibblerSDL.cpp for nibbler in /home/schric_a/Tek2/CPP/cpp_nibbler/nibblerSDL/
//
// Made by Adrien Schricke
// Login   <schric_a@epitech.eu>
//
// Started on  Mon Mar 30 14:44:26 2015 Adrien Schricke
// Last update Tue Mar 31 16:39:15 2015 Adrien Schricke
//

#include "nibblerSDL.hh"

extern "C" IDisplayModule *getClass()
{
    return (new NibblerSDL());
}

NibblerSDL::NibblerSDL()
{
// a supprimer
    this->name = "yolo";
}

NibblerSDL::~NibblerSDL()
{

}

//A supprimer
std::string const & NibblerSDL::getName() const
{
    return (this->name);
}


void NibblerSDL::createWin(int x, int y)
{
    SDL_Init(SDL_INIT_VIDEO);
    this->win = SDL_SetVideoMode(x * (this->space + this->ox), y * (this->space + this->oy), 32, SDL_HWSURFACE);
    if (this->win == NULL)
    {
      throw(SDL_GetError());
    }
    SDL_WM_SetCaption("Nibbler - lib SDL", NULL);
    SDL_FillRect(this->win, NULL, SDL_MapRGB((this->win)->format, 0, 0, 0));
    SDL_Flip(this->win);
}

void NibblerSDL::init(int x, int y)
{
    this->x = x;
    this->y = y;
    this->space = 40;
    this->ox = 10;
    this->oy = 10;
    this->createWin(x, y);

}

void NibblerSDL::stop()
{
    //SDL_DestroyWindow(this->win);
    SDL_Quit();
}

t_dir NibblerSDL::getEvent()
{
    SDL_Event       event;

    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT)
    {
        this->stop();
        return END;
    }
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_RIGHT)
            return RIGHT;
        else if (event.key.keysym.sym == SDLK_LEFT)
            return LEFT;
        else if (event.key.keysym.sym == SDLK_UP)
            return UP;
        else if (event.key.keysym.sym == SDLK_DOWN)
            return DOWN;
        else if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            this->stop();
            return END;
        }
        else
            return NOTHING;
    }
    return (NOTHING);
}

int NibblerSDL::refreshScreen()
{
    SDL_Surface     *pion;
    SDL_Rect        pos;

    for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j < this->y; j++)
        {
            pion = SDL_CreateRGBSurface(SDL_HWSURFACE, this->space, this->space, 32, 0, 0, 0, 0);
            pos.x = this->ox + (this->space * i + this->ox * i);
            pos.y = this->oy + (this->space * j + this->ox * j);
            SDL_FillRect(pion, NULL, SDL_MapRGB(this->win->format, 255, 255, 255));
            SDL_BlitSurface(pion, NULL, this->win, &pos);
            SDL_Flip(this->win);
            SDL_FreeSurface(pion);
        }
    }
    return (0);
}

int NibblerSDL::drawGame(int x, int y, t_type tp)
{
    SDL_Surface     *pion;
    SDL_Rect        pos;

    pion = SDL_CreateRGBSurface(SDL_HWSURFACE, this->space, this->space, 32, 0, 0, 0, 0);
    pos.x = this->ox + (this->space * x + this->ox * x);
    pos.y = this->oy + (this->space * y + this->ox * y);
    if (tp == HEAD)
        SDL_FillRect(pion, NULL, SDL_MapRGB(this->win->format, 150, 150, 50));
    else if (tp == BODY)
        SDL_FillRect(pion, NULL, SDL_MapRGB(this->win->format, 0, 150, 0));
    else if (tp == TAIL)
        SDL_FillRect(pion, NULL, SDL_MapRGB(this->win->format, 0, 0, 150));
    else
        SDL_FillRect(pion, NULL, SDL_MapRGB(this->win->format, 255, 0, 0));
    SDL_BlitSurface(pion, NULL, this->win, &pos);
    SDL_Flip(this->win);
    SDL_FreeSurface(pion);
    return (0);
}

int NibblerSDL::timeToWait(int ms)
{
    usleep(ms);
    return (0);
}

void NibblerSDL::printSomething(const std::string & str)
{

}
