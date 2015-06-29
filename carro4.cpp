#include "carro4.h"

carro4::carro4(SDL_Renderer* renderer, int pos)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "I - carro4.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = pos;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;
}

void carro4::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void carro4::logica()
{
    rect_textura.y+=20;
}

carro4::~carro4()
{
    //dtor
}
