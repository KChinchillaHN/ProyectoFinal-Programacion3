#include "personaje.h"
#ifndef CARRO4_H
#define CARRO4_H


class carro4 : public personaje
{
    public:
        void dibujar();
        void logica();

        carro4(SDL_Renderer* renderer, int pos);
        virtual ~carro4();
    protected:
    private:
};

#endif // CARRO4_H
