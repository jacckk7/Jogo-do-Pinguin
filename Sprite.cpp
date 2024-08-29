#include "Game.h"

Sprite::Sprite() {
	texture = nullptr;
}

Sprite::Sprite(string file) {
	texture = nullptr;
	Open(file);
	SetClip(0, 0, width, height);
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

void Sprite::Open(string file) {
	if (IsOpen()) {
		SDL_DestroyTexture(texture);
	}
	texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	cout << SDL_GetError() << endl;
}

void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render(int x, int y) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = clipRect.w;
	dst.h = clipRect.h;

	SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dst);
}

int Sprite::GetWidth() {
	return clipRect.w;
}

int Sprite::GetHeight() {
	return clipRect.h;
}

bool Sprite::IsOpen(){
	if (texture == nullptr) {
		return false;
	}

	return true;
}