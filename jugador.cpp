#include "jugador.h"

jugador::jugador(SDL_Renderer *renderer,list<personaje*>*personajes)
{
    this->renderer = renderer;
    this->personajes = personajes;
    int w,h;
    textura = IMG_LoadTexture(renderer, "jugador.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 100;
    rect_textura.y = 100;
    rect_textura.w = w;
    rect_textura.h = h;

    velocidad=3;
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
        rect_textura.x-=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_RIGHT])
    {
        rect_textura.x+=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_UP])
    {
        rect_textura.y-=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_DOWN])
    {
        rect_textura.y+=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_Z])
    {
        if(frame%10==0)
        {
            SDL_Rect temp;
            temp.x=rect_textura.x;
            temp.y=rect_textura.y+15;
        }
    }
    for(list<personaje*>::iterator i=personajes->begin();
        i!=personajes->end();
        i++
        )
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
