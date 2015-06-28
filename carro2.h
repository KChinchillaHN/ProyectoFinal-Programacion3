#include "personaje.h"
#ifndef CARRO2_H
#define CARRO2_H


class carro2 : public personaje
{
    public:
        void dibujar();
        void logica();

        carro2(SDL_Renderer* renderer);
        virtual ~carro2();
    protected:
    private:
};

#endif // CARRO2_H
