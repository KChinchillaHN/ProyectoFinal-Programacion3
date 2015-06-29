#include "personaje.h"
#ifndef CUADRO_SINACCION_H
#define CUADRO_SINACCION_H


class Cuadro_SinAccion : public personaje
{
    public:
        void dibujar();
        void logica();

        Cuadro_SinAccion(SDL_Renderer* renderer);
        virtual ~Cuadro_SinAccion();
    protected:
    private:
};

#endif // CUADRO_SINACCION_H
