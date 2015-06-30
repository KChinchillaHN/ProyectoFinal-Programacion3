#include "jugador.h"

jugador::jugador(SDL_Renderer *renderer,list<personaje*>*personajes)
{
    this->renderer = renderer;
    this->personajes = personajes;
    int w,h;
    textura = IMG_LoadTexture(renderer, "I - carro5.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 300;
    rect_textura.y = 605;
    rect_textura.w = w;
    rect_textura.h = h;

    velocidad=5;
}

void jugador::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void jugador::logica()
{

    const Uint8* estaPresionada = SDL_GetKeyboardState( NULL );
    if(estaPresionada[ SDL_SCANCODE_LEFT])
    {
        if (rect_textura.x>40)
        rect_textura.x-=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_RIGHT])
    {
        if (rect_textura.x<540)
        rect_textura.x+=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_UP])
    {
        if (rect_textura.y>7)
        rect_textura.y-=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_DOWN])
    {
        if (rect_textura.y<605)
        rect_textura.y+=velocidad;
    }
    for(list<personaje*>::iterator i=personajes->begin();i!=personajes->end();i++)
    {
        if(*i==this)
            continue;
    }
    frame++;
}

jugador::~jugador()
{
    //dtor
}
