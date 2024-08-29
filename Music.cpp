#include "Game.h"

Music::Music() {
	music = nullptr;
}

Music::Music(string file) {
	music = nullptr;
	Open(file);
	Play();
}

Music::~Music() {
	Stop();
	Mix_FreeMusic(music);
}

void Music::Play(int times) {
	if (IsOpen()) {
		Mix_PlayMusic(music, times);
	}
}

void Music::Stop(int msToStop) {
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file) {
	music = Mix_LoadMUS(file.c_str());
}

bool Music::IsOpen() {
	if (music == nullptr) {
		return false;
	}
	
	return true;
}