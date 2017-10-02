#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <SDL.h>
#include <iomanip>
#include <math.h>

class Screen
{
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	Uint32 *buffer1;
	Uint32 *buffer2;
	
public:
	Screen();
	bool init();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void update();
	bool processEvents();
	void close();
	void boxBlur();
};

#endif
