#include "carro2.h"

carro2::carro2(SDL_Renderer* renderer, int pos2)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "I - carro2.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = pos2;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;
}

void carro2::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void carro2::logica()
{
    rect_textura.y+=10;
}

carro2::~carro2()
{
    //dtor
}
