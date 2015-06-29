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
            Mix_PlayMusic(gMusic,-1);
        }
    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", SDL_GetError());
        }
    gMusic=Mix_LoadMUS("Thunderstruck.mp3");
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
    gMusic=Mix_LoadMUS("Fade.mp3");
    if(gMusic==NULL)
        {
            printf("Error loading: %s\n", Mix_GetError());
        }
    }

}

void juegoFacil()
{
    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"Pantalla.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

//
//    float enemigo_y = 0;


    //Main Loop
    float personaje_x = 100;
    float personaje_y = 100;

    unsigned int frame_anterior = SDL_GetTicks();

    list<personaje*>personajes;
    personajes.push_back(new carro1(renderer));
    personajes.push_back(new carro2(renderer));
    personajes.push_back(new carro3(renderer));
    personajes.push_back(new carro4(renderer));
    personajes.push_back(new jugador(renderer,&personajes));

    int frame=0;

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
             musicaMenu(2);
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
            }
        }

        for(list<personaje*>::iterator i=personajes.begin();
            i!=personajes.end();
            i++)
            (*i)->logica();

        SDL_RenderCopy(renderer, background, NULL, &rect_background);

        for(list<personaje*>::iterator i=personajes.begin();
            i!=personajes.end();
            i++)
            (*i)->dibujar();

        if((SDL_GetTicks()-frame_anterior)<17)
            SDL_Delay(17-(SDL_GetTicks()-frame_anterior));
        frame_anterior=SDL_GetTicks();

        SDL_RenderPresent(renderer);
        frame++;
    }
}

void menu()
{
    int w,h;
    SDL_Texture* background_menu = IMG_LoadTexture(renderer,"Menu.png");
    SDL_QueryTexture(background_menu, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;


    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            musicaMenu(1);
            if(Event.type == SDL_QUIT)
            {

                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_f)
                {
                    juegoFacil();
                }
            }
        }
        SDL_RenderCopy(renderer, background_menu, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }

}


int main( int argc, char* args[] )
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
