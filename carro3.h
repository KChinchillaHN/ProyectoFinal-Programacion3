#include "personaje.h"
#ifndef CARRO3_H
#define CARRO3_H


class carro3 : public personaje
{
    public:
        void dibujar();
        void logica();

        carro3(SDL_Renderer* renderer);
        virtual ~carro3();
    protected:
    private:
};

#endif // CARRO3_H
