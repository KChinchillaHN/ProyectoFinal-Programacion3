#include "carro1.h"

carro1::carro1(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "carro1.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 100;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;
}

void carro1::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void carro1::logica()
{
    rect_textura.y+=5;
}

carro1::~carro1()
{
    //dtor
}
