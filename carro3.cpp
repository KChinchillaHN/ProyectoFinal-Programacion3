#include "carro3.h"

carro3::carro3(SDL_Renderer* renderer, int pos)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "I - carro3.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = pos;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;
}


void carro3::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void carro3::logica()
{
    rect_textura.y+=20;
}

carro3::~carro3()
{
    //dtor
}
