#include <stdio.h>
#include "SDL2/SDL.h"
#define WINDOWS_HEIGHT 480
#define WINDOWS_LENGTH 640
struct rect {
	int x, y; 
} RECT1;


int main() {
	SDL_Window *window;
	window = SDL_CreateWindow(
							 	"title",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								WINDOWS_LENGTH,
								WINDOWS_HEIGHT,
								0
								);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, 
												-1, 
												SDL_RENDERER_ACCELERATED |
												SDL_RENDERER_PRESENTVSYNC);
	SDL_Event e;
	int quit = 0;
	struct rect RECT1;
	RECT1.x = RECT1.y = 0;
	while(!quit) {
		while(SDL_PollEvent(&e)) {
			switch(e.type) {
				case SDL_QUIT:
					quit = 1;	
					break;
			}
			switch(e.key.keysym.sym) {
				case SDLK_UP:
					RECT1.y -= 10;
					break;
				case SDLK_DOWN:
					RECT1.y += 10;
					break;
				case SDLK_LEFT:
					RECT1.x -= 10;
					break;
				case SDLK_RIGHT:
					RECT1.x += 10;
					break;
				default:{}
			}
		}
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
		SDL_Rect rectx = {	(WINDOWS_LENGTH  / 2 - WINDOWS_LENGTH / 30 ) + RECT1.x,
						  	0,
						   	WINDOWS_LENGTH / 15,
						  	WINDOWS_HEIGHT,
						};
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &rectx);
		SDL_Rect recty = {	0,
							(WINDOWS_HEIGHT  / 2 - WINDOWS_HEIGHT / 30 ) + RECT1.y,
						   	WINDOWS_LENGTH,
						  	WINDOWS_HEIGHT / 15,
						};
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &recty);
		SDL_Rect rect1 = {	(WINDOWS_LENGTH / 4) + RECT1.x,
						  	(WINDOWS_HEIGHT / 4) + RECT1.y ,
						   	WINDOWS_LENGTH / 2,
						  	WINDOWS_HEIGHT / 2,
						};
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(renderer, &rect1);
		SDL_Rect rect2 = {	(WINDOWS_LENGTH / 2  - WINDOWS_LENGTH / 8 ) + RECT1.x,
						  	(WINDOWS_HEIGHT / 2  - WINDOWS_HEIGHT / 8 ) + RECT1.y ,
						   	WINDOWS_LENGTH / 4,
						  	WINDOWS_HEIGHT / 4,
						};
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &rect2);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
