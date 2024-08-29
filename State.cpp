#include "Game.h"

State::State():bg(Sprite("img/ocean.jpg")),music(Music("audio/stageState.ogg")) {
	quitRequested = false;
}

void State::LoadAssets() {

}

void State::Update(float dt) {
	if (SDL_QuitRequested()) {
		quitRequested = true;
	}
}

void State::Render() {
	bg.Render(0, 0);
}

bool State::QuitRequested() {
	return quitRequested;
}

