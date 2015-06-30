#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<list>

#include "personaje.h"
#include "carro1.h"
#include "carro2.h"
#include "carro3.h"
#include "carro4.h"
#include "jugador.h"
#include "Cuadro_SinAccion.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background;
SDL_Rect rect_background;
Mix_Music *gMusic = NULL;

void musicaMenu(int NivelM)
{
    if (NivelM==1)
    {
    if(Mix_PlayingMusic()==0)
        {
            Mix_PlayMusic(gMusic, -1);
        }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", SDL_GetError());
        }
    gMusic=Mix_LoadMUS("M - Facil.mp3");
    if(gMusic==NULL)
        {
            printf("Error loading: %s\n", Mix_GetError());
        }
    }

    if (NivelM==2)
    {
    if(Mix_PlayingMusic()==0)
        {
            Mix_PlayMusic(gMusic,-1);
        }
    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", SDL_GetError());
        }
    gMusic=Mix_LoadMUS("M - Medio.mp3");
    if(gMusic==NULL)
        {
            printf("Error loading: %s\n", Mix_GetError());
        }
    }

    if (NivelM==3)
    {
    if(Mix_PlayingMusic()==0)
        {
            Mix_PlayMusic(gMusic,-1);
        }
    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", SDL_GetError());
        }
    gMusic=Mix_LoadMUS("M - Dificil.mp3");
    if(gMusic==NULL)
        {
            printf("Error loading: %s\n", Mix_GetError());
        }
    }

    if (NivelM==4)
    {
    if(Mix_PlayingMusic()==0)
        {
            Mix_PlayMusic(gMusic,-1);
        }
    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", SDL_GetError());
        }
    gMusic=Mix_LoadMUS("M - Super.mp3");
    if(gMusic==NULL)
        {
            printf("Error loading: %s\n", Mix_GetError());
        }
    }
}

void juegoFacil()
{
    int w=0,h=0;
    int pos=40, pos2=1000, pos3=1000, pos4=1040;
    int posb=540, pos2b=540, pos3b=540, pos4b=540;
    background = IMG_LoadTexture(renderer,"I - Pantalla.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    unsigned int frame_anterior = SDL_GetTicks();
    int frame=0;
    musicaMenu(1);

    list<personaje*>personajes;
    personajes.push_back(new carro1(renderer, pos));
    personajes.push_back(new carro2(renderer, pos2));
    personajes.push_back(new carro3(renderer, pos3));
    personajes.push_back(new carro4(renderer, pos4));
    personajes.push_back(new jugador(renderer,&personajes));

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
            }
        }

        if(frame<5000)
        {
            if(frame%140==0)
            {
                personajes.push_back(new carro1(renderer, pos));
                pos+=39;
                if(pos>550)
                    pos=40;

                personajes.push_back(new carro1(renderer, posb));
                posb-=39;
                if(posb<40)
                    posb=551;
            }
        }

        if(frame>1000&frame<5000)
        {
            if(frame%140==0)
            {
                personajes.push_back(new carro2(renderer, pos2));
                pos2+=50;
                if(pos2>540)
                    pos2=50;

                personajes.push_back(new carro2(renderer, pos2b));
                pos2b-=50;
                if(pos2b<50)
                    pos2b=540;
            }
        }

        if(frame>3500&frame<5000)
        {
            if(frame%140==0)
            {
                personajes.push_back(new carro3(renderer, pos3));
                pos3+=60;
                if(pos2>551)
                    pos2=50;

                personajes.push_back(new carro3(renderer, pos3b));
                pos3b-=60;
                if(pos3b<50)
                    pos3b=550;
            }
        }

    for(list<personaje*>::iterator i=personajes.begin();i!=personajes.end();i++)
    (*i)->logica();
    SDL_RenderCopy(renderer, background, NULL, &rect_background);

    for(list<personaje*>::iterator i=personajes.begin();i!=personajes.end();i++)
    (*i)->dibujar();

    if((SDL_GetTicks()-frame_anterior)<17)
        SDL_Delay(17-(SDL_GetTicks()-frame_anterior));

    frame_anterior=SDL_GetTicks();
    SDL_RenderPresent(renderer);
    frame++;
    }
}

void juegoMedio()
{
    int w=0,h=0;
    int pos=40, pos2=1000, pos3=1000, pos4=1040;
    int posb=540, pos2b=540, pos3b=540, pos4b=540;
    background = IMG_LoadTexture(renderer,"I - Pantalla.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    unsigned int frame_anterior = SDL_GetTicks();
    int frame=0;
    musicaMenu(2);

    list<personaje*>personajes;
    personajes.push_back(new carro1(renderer, pos));
    personajes.push_back(new carro2(renderer, pos2));
    personajes.push_back(new carro3(renderer, pos3));
    personajes.push_back(new carro4(renderer, pos4));
    personajes.push_back(new jugador(renderer,&personajes));

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
            }
        }

        if(frame<6000)
        {
            if(frame%130==0)
            {
                personajes.push_back(new carro1(renderer, pos));
                pos+=39;
                if(pos>550)
                    pos=40;

                personajes.push_back(new carro1(renderer, posb));
                posb-=39;
                if(posb<40)
                    posb=551;
            }
        }

        if(frame>1000&frame<6000)
        {
            if(frame%130==0)
            {
                personajes.push_back(new carro2(renderer, pos2));
                pos2+=50;
                if(pos2>540)
                    pos2=50;

                personajes.push_back(new carro2(renderer, pos2b));
                pos2b-=50;
                if(pos2b<50)
                    pos2b=540;
            }
        }

        if(frame>3000&frame<6000)
        {
            if(frame%130==0)
            {
                personajes.push_back(new carro3(renderer, pos3));
                pos3+=60;
                if(pos2>551)
                    pos2=50;

                personajes.push_back(new carro3(renderer, pos3b));
                pos3b-=60;
                if(pos3b<50)
                    pos3b=550;
            }
        }

    for(list<personaje*>::iterator i=personajes.begin();i!=personajes.end();i++)
    (*i)->logica();
    SDL_RenderCopy(renderer, background, NULL, &rect_background);

    for(list<personaje*>::iterator i=personajes.begin();i!=personajes.end();i++)
    (*i)->dibujar();

    if((SDL_GetTicks()-frame_anterior)<17)
        SDL_Delay(17-(SDL_GetTicks()-frame_anterior));

    frame_anterior=SDL_GetTicks();
    SDL_RenderPresent(renderer);
    frame++;
    }
}

void juegoDificil()
{
    int w=0,h=0;
    int pos=40, pos2=1000, pos3=1000, pos4=1040;
    int posb=540, pos2b=540, pos3b=540, pos4b=540;
    background = IMG_LoadTexture(renderer,"I - Pantalla.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    unsigned int frame_anterior = SDL_GetTicks();
    int frame=0;
    musicaMenu(3);

    list<personaje*>personajes;
    personajes.push_back(new carro1(renderer, pos));
    personajes.push_back(new carro2(renderer, pos2));
    personajes.push_back(new carro3(renderer, pos3));
    personajes.push_back(new carro4(renderer, pos4));
    personajes.push_back(new jugador(renderer,&personajes));

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
            }
        }

        if(frame<7000)
        {
            if(frame%120==0)
            {
                personajes.push_back(new carro1(renderer, pos));
                pos+=39;
                if(pos>550)
                    pos=40;

                personajes.push_back(new carro1(renderer, posb));
                posb-=39;
                if(posb<40)
                    posb=551;
            }
        }

        if(frame>500&frame<7000)
        {
            if(frame%120==0)
            {
                personajes.push_back(new carro2(renderer, pos2));
                pos2+=50;
                if(pos2>540)
                    pos2=50;

                personajes.push_back(new carro2(renderer, pos2b));
                pos2b-=50;
                if(pos2b<50)
                    pos2b=540;
            }
        }

        if(frame>2000&frame<7000)
        {
            if(frame%140==0)
            {
                personajes.push_back(new carro3(renderer, pos3));
                pos3+=60;
                if(pos2>551)
                    pos2=50;

                personajes.push_back(new carro3(renderer, pos3b));
                pos3b-=60;
                if(pos3b<50)
                    pos3b=550;
            }
        }

    for(list<personaje*>::iterator i=personajes.begin();i!=personajes.end();i++)
    (*i)->logica();
    SDL_RenderCopy(renderer, background, NULL, &rect_background);

    for(list<personaje*>::iterator i=personajes.begin();i!=personajes.end();i++)
    (*i)->dibujar();

    if((SDL_GetTicks()-frame_anterior)<17)
        SDL_Delay(17-(SDL_GetTicks()-frame_anterior));

    frame_anterior=SDL_GetTicks();
    SDL_RenderPresent(renderer);
    frame++;
    }
}

void juegoSuper()
{
    int w=0,h=0;
    int pos=40, pos2=1000, pos3=50, pos4=50;
    int posb=540, pos2b=540, pos3b=540, pos4b=540;
    background = IMG_LoadTexture(renderer,"I - Pantalla.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    unsigned int frame_anterior = SDL_GetTicks();
    int frame=0;
    musicaMenu(4);

    list<personaje*>personajes;
    personajes.push_back(new carro1(renderer, pos));
    personajes.push_back(new carro2(renderer, pos2));
    personajes.push_back(new carro3(renderer, pos3));
    personajes.push_back(new carro4(renderer, pos4));
    personajes.push_back(new jugador(renderer,&personajes));

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
            }
        }

        if(frame>200 & frame<1300)
        {
            if(frame%140==0)
            {
                personajes.push_back(new carro1(renderer, pos));
                pos+=39;
                if(pos>550)
                    pos=40;

                personajes.push_back(new carro1(renderer, posb));
                posb-=39;
                if(posb<40)
                    posb=551;
            }
        }

        if(frame>1300&frame<10000)
        {
            if(frame%120==0)
            {
                personajes.push_back(new carro3(renderer, pos3));
                pos3+=50;
                if(pos3>540)
                    pos3=50;

                personajes.push_back(new carro3(renderer, pos3b));
                pos3b-=50;
                if(pos3b<50)
                    pos3b=540;
            }
        }

        if(frame>1600&frame<10000)
        {

            if(frame%120==0)
            {
                personajes.push_back(new carro4(renderer, pos4));
                pos4+=50;
                if(pos4>540)
                    pos4=50;

                personajes.push_back(new carro4(renderer, pos4b));
                pos4b-=50;
                if(pos4b<50)
                    pos4b=540;
            }
        }

    for(list<personaje*>::iterator i=personajes.begin();i!=personajes.end();i++)
    (*i)->logica();
    SDL_RenderCopy(renderer, background, NULL, &rect_background);

    for(list<personaje*>::iterator i=personajes.begin();i!=personajes.end();i++)
    (*i)->dibujar();

    if((SDL_GetTicks()-frame_anterior)<17)
        SDL_Delay(17-(SDL_GetTicks()-frame_anterior));

    frame_anterior=SDL_GetTicks();
    SDL_RenderPresent(renderer);
    frame++;
    }
}

void Instrucciones()
{
    int w=0,h=0;
    SDL_Texture* background_instrucciones = IMG_LoadTexture(renderer,"I - Instrucciones.png");
    SDL_QueryTexture(background_instrucciones, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
            }
        }
    SDL_RenderCopy(renderer, background_instrucciones, NULL, &rect_background);
    SDL_RenderPresent(renderer);
    }
}

void Puntuacion()
{
    int w=0,h=0;
    SDL_Texture* background_instrucciones = IMG_LoadTexture(renderer,"I - Mejor_Puntaje.png");
    SDL_QueryTexture(background_instrucciones, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
            }
        }
    SDL_RenderCopy(renderer, background_instrucciones, NULL, &rect_background);
    SDL_RenderPresent(renderer);
    }
}

void menu()
{
    while(true)
    {
        Mix_PauseMusic();
        Mix_HaltMusic();
        while(SDL_PollEvent(&Event))
        {
        int w,h;
        SDL_Texture* background_menu = IMG_LoadTexture(renderer,"I - Menu.png");
        SDL_QueryTexture(background_menu, NULL, NULL, &w, &h);
        rect_background.x = 0;
        rect_background.y = 0;
        rect_background.w = w;
        rect_background.h = h;
        if(Event.type == SDL_KEYDOWN)
        {
            if(Event.key.keysym.sym == SDLK_f)
                {
                    juegoFacil();
                }
            if(Event.key.keysym.sym == SDLK_m)
                {
                    juegoMedio();
                }
            if(Event.key.keysym.sym == SDLK_d)
                {
                    juegoDificil();
                }
            if(Event.key.keysym.sym == SDLK_s)
                {
                    juegoSuper();
                }
            if(Event.key.keysym.sym == SDLK_p)
                {
                    Puntuacion();
                }
            if(Event.key.keysym.sym == SDLK_t)
                {
                    exit(0);
                }

            if(Event.key.keysym.sym == SDLK_i)
                {
                    Instrucciones();
                }
        }
        SDL_RenderCopy(renderer, background_menu, NULL, &rect_background);
        SDL_RenderPresent(renderer);
        }
    }
}

int main()
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 900/*WIDTH*/, 700/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    menu();
	return 0;
}
