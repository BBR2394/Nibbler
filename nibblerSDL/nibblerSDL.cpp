//
// nibblerSDL.cpp for nibbler in /home/schric_a/Tek2/CPP/cpp_nibbler/nibblerSDL/
//
// Made by Adrien Schricke
// Login   <schric_a@epitech.eu>
//
// Started on  Mon Mar 30 14:44:26 2015 Adrien Schricke
// Last update Wed Apr  1 16:06:41 2015 Adrien Schricke
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
//    this->win = SDL_SetVideoMode(x * (this->space + this->ox) + this->ox, y * (this->space + this->oy) + this->oy, 32, SDL_HWSURFACE);
    this->win = SDL_SetVideoMode(1000 + this->ox, 1000, 32, SDL_HWSURFACE);
    if (this->win == NULL)
      throw(SDL_GetError());
    SDL_WM_SetCaption("Nibbler - lib SDL", NULL);
    SDL_FillRect(this->win, NULL, SDL_MapRGB((this->win)->format, 0, 0, 0));
    SDL_Flip(this->win);
}

void NibblerSDL::init(int x, int y)
{
    this->x = x;
    this->y = y;
    this->space = 20;
    this->ox = 1;
    this->oy = 1;
    this->last_x = -1;
    this->last_y = -1;
    this->createWin(x, y);
    this->color_head = SDL_MapRGB(this->win->format, 150, 150, 250);
    this->color_body = SDL_MapRGB(this->win->format, 150, 0, 250);
    this->color_tail = SDL_MapRGB(this->win->format, 0, 0, 250);
    this->color_apple = SDL_MapRGB(this->win->format, 255, 0, 0);
    this->color_back = SDL_MapRGB(this->win->format, 255, 255, 255);

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
            return DOWN;
        else if (event.key.keysym.sym == SDLK_DOWN)
            return UP;
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
    static bool     init = true;

    if (init == true)
    {
        for (int i = 0; i < this->x; i++)
        {
            for (int j = 0; j < this->y; j++)
            {
                pion = SDL_CreateRGBSurface(SDL_HWSURFACE, this->space, this->space, 32, 0, 0, 0, 0);
                pos.x = this->ox + (this->space * i + this->ox * i);
                pos.y = this->oy + (this->space * j + this->ox * j);
                SDL_FillRect(pion, NULL, this->color_back);
                SDL_BlitSurface(pion, NULL, this->win, &pos);
                SDL_Flip(this->win);
                SDL_FreeSurface(pion);
            }
        }
        init = false;
    }
    return (0);
}

int NibblerSDL::drawGame(int x, int y, t_type tp)
{
    SDL_Surface     *pion;
    SDL_Surface     *gomme;
    SDL_Rect        pos;
    SDL_Rect        pgom;

    pion = SDL_CreateRGBSurface(SDL_HWSURFACE, this->space, this->space, 32, 0, 0, 0, 0);
    gomme = SDL_CreateRGBSurface(SDL_HWSURFACE, this->space, this->space, 32, 0, 0, 0, 0);
    pos.x = this->ox + (this->space * x + this->ox * x);
    pos.y = this->oy + (this->space * y + this->ox * y);
    if (tp == HEAD)
        SDL_FillRect(pion, NULL, this->color_head);
    else if (tp == BODY)
        SDL_FillRect(pion, NULL, this->color_body);
    else if (tp == TAIL)
        {
            SDL_FillRect(pion, NULL, this->color_tail);
            if (this->last_x >= 0 && this->last_y >= 0)
                {
                    pgom.x = this->ox + (this->space * this->last_x + this->ox * this->last_x);
                    pgom.y = this->oy + (this->space * this->last_y + this->ox * this->last_y);
                    SDL_FillRect(gomme, NULL, this->color_back);
                }
            this->last_x = x;
            this->last_y = y;
        }
    else
        SDL_FillRect(pion, NULL, this->color_apple);
    SDL_BlitSurface(pion, NULL, this->win, &pos);
    SDL_BlitSurface(gomme, NULL, this->win, &pgom);

    SDL_Flip(this->win);
    SDL_FreeSurface(pion);
    SDL_FreeSurface(gomme);
    return (0);
}

int NibblerSDL::timeToWait(int ms)
{
    usleep(ms * 10);
    return (0);
}

void NibblerSDL::printSomething(const std::string & str)
{

}
