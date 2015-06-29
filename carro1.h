#include "personaje.h"
#ifndef CARRO1_H
#define CARRO1_H


class carro1 : public personaje
{
    public:
        void dibujar();
        void logica();

        carro1(SDL_Renderer* renderer, int pos);
        virtual ~carro1();
    protected:
    private:
};


#endif // CARRO1_H
