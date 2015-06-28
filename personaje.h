#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class personaje
{
    public:
        SDL_Texture *textura;
        SDL_Rect rect_textura;
        SDL_Renderer *renderer;

        int frame;
        personaje();
        virtual void logica()=0;
        virtual void dibujar()=0;
        virtual ~personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
