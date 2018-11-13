#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
using namespace std;

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRetangle;
	SDL_Rect m_destinationRectangle;

	bool m_bRunning;
};