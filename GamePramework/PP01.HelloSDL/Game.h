#pragma once
#include "TextureManager.h"
#include <SDL.h>
#include <SDL_image.h>

class Game
{
	int m_currentFrame;

public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void render();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};