#include "personaje.h"
#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <list>
#include <iostream>

using namespace std;

class jugador : public personaje
{
    public:
        list<personaje*>*personajes;
        int velocidad;

        void dibujar();
        void logica();

        jugador(SDL_Renderer *renderer,list<personaje*>*personajes);
        virtual ~jugador();
    protected:
    private:
};

#endif // JUGADOR_H
