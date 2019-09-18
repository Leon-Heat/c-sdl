#include <stdio.h>
#include "SDL2/SDL.h"
#define	WINDOWPOS_X		SDL_WINDOWPOS_CENTERED
#define	WINDOWPOS_Y		SDL_WINDOWPOS_CENTERED
#define	WINDOWS_HEIGHT		480
#define	WINDOWS_LENGTH		640
int main() {
	SDL_Window *window;
	window = SDL_CreateWindow(
					"rect",
					WINDOWPOS_X,
					WINDOWPOS_Y,
					WINDOWS_LENGTH,
					WINDOWS_HEIGHT,
					0
					);
	if(window == NULL) {
		printf("Window is fk\t%s\n", SDL_GetError());
	}
	SDL_Renderer *renderer;
	renderer = SDL_CreateRenderer(window, -1,
								  SDL_RENDERER_ACCELERATED |
								  SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL) {
		SDL_DestroyWindow(window);
		printf("renderer is fk\t%s\n", SDL_GetError());
	}
	SDL_Event e;
	int quit = 0;
	while(!quit) {
		while(SDL_PollEvent(&e)) {
			switch(e.type) {
				case SDL_QUIT:
					quit = 1;
					break;	
				default:{}
			}
		}	
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
	SDL_Rect rect1 = {	WINDOWS_LENGTH / 4,
					  	WINDOWS_HEIGHT / 4,
					  	WINDOWS_LENGTH / 2,
					  	WINDOWS_HEIGHT / 2,
						};
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &rect1);
	SDL_Rect rect2 = {	WINDOWS_LENGTH / 6,
					  	WINDOWS_HEIGHT / 6,
					  	WINDOWS_LENGTH * 2 / 3,
					  	WINDOWS_HEIGHT * 2 / 3,
						};
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, &rect2);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
//	SDL_RenderDrawLine(renderer, 0, 0, WINDOWS_HEIGHT / 3, WINDOWS_LENGTH / 10);
	SDL_RenderDrawLine(renderer, 0, WINDOWS_HEIGHT / 2, WINDOWS_LENGTH, WINDOWS_HEIGHT / 2);
	for(int i = 0; i <= WINDOWS_HEIGHT; i +=5){
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawPoint(renderer, WINDOWS_LENGTH / 2, i);
	}
	SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
