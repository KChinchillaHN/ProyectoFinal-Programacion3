#include "carro2.h"

carro2::carro2(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "carro2.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 200;
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
    rect_textura.y+=0;
}

carro2::~carro2()
{
    //dtor
}
