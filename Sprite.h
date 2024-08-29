#pragma once
#include "Game.h"

using namespace std;

class Sprite {
private:
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;

public:
	Sprite();
	Sprite(string);
	~Sprite();
	void Open(string);
	void SetClip(int, int, int, int);
	void Render(int, int);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
};