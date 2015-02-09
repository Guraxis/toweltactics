#include <SDL.h>
#include <SDL_image.h>
#include <math.h>
#include <list>
#include <sys/time.h>

#include "main.h"
#include "obrazek.h"

#define RESX 800
#define RESY 600

Obrazovka* obrazovka = Obrazovka::instance();
int main(int argc, char *argv[])
{
	int t1, t2;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	obrazovka->inicializuj(RESX, RESY, 0, 0);

	while (1)
	{
		t1 = SDL_GetTicks();
		SDL_FillRect(obrazovka->screen, NULL, 0);

		barva(255,255,255);
		for(int i=50; i<600; i+=50)
		{
			cara(150,i,650,i);
		}
		for(int i=150; i<700; i+=50)
		{
			cara(i,50,i,550);
		}


		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					SDL_Quit();
					return 1;
				}
			case SDL_QUIT:
				SDL_Quit();
				return 1;
			}
		}

		obrazovka->aktualizuj();

		t2 = SDL_GetTicks();
		if(t2-t1<=17)
		{
			SDL_Delay(17-(t2-t1));
		}
	}
}
