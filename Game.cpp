#include "Game.h"

Game* Game::instance = nullptr;

Game::Game(string title, int width, int height) {
	if (instance == nullptr) {
		instance = this;
	}
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	cout << SDL_GetError() << endl;
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(32);
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	state = new State();
}

Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

Game& Game::GetInstance() {
	if (instance != nullptr) {
		return *instance;
	}
	else {
		Game* instance = new Game("Jogo do Pinguin", 1024, 600);
		return *instance;
	}
}

State& Game::GetState() {
	if (state != nullptr) {
		return *state;
	}
}

SDL_Renderer* Game::GetRenderer() {
	return renderer;
}

void Game::Run() {
	while (!state->QuitRequested()) {
		state->Update(0);
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(16.5);
	}
}