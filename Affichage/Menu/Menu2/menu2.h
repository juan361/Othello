#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

typedef struct Texture Texture;

struct Texture
{
	SDL_Texture *texture;
	Texture *other;
};

typedef struct
{
	SDL_Renderer *renderer;
	SDL_Window *window;
	Texture textureHead, *textureTail;
	void (*logic)();
	void (*draw)();
} SDL_Context;

SDL_Context sdl;