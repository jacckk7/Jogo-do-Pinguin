#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>

#include "SDL_include.h"
#include "State.h"
#include "Sprite.h"
#include "Music.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

using namespace std;

class Game {
private:
	Game(string, int, int);

	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;

public:
	~Game();
	void Run();
	SDL_Renderer* GetRenderer();
	State& GetState();
	static Game& GetInstance();
};