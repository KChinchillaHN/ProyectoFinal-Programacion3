#include "Cuadro_SinAccion.h"

Cuadro_SinAccion::Cuadro_SinAccion(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "I - Cuadro_Abajo.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 0;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;
}

void Cuadro_SinAccion::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void Cuadro_SinAccion::logica()
{
    rect_textura.y+=0;
}

Cuadro_SinAccion::~Cuadro_SinAccion()
{
    //dtor
}
