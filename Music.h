#pragma once
#include "Game.h"

class Music {
private:
	Mix_Music* music;

public:
	Music();
	Music(string);
	~Music();
	void Play(int = -1);
	void Stop(int = 1500);
	void Open(string);
	bool IsOpen();
};