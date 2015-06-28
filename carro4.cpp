#include "carro4.h"

carro4::carro4(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "carro4.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 400;
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
    rect_textura.y+=0;
}

carro4::~carro4()
{
    //dtor
}
