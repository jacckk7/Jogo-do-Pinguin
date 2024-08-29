#pragma once
#include "Game.h"
#include "Sprite.h"
#include "Music.h"

using namespace std;

class State {
private:
	Sprite bg;
	Music music;
	bool quitRequested;

public:
	State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float);
	void Render();
};