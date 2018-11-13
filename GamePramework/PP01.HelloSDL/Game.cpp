#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;

		SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		
		m_sourceRetangle.w = 128;
		m_sourceRetangle.h = 82;

		m_destinationRectangle.x = m_sourceRetangle.x = 0;
		m_destinationRectangle.y = m_sourceRetangle.y = 0;
		m_destinationRectangle.w = m_sourceRetangle.w;
		m_destinationRectangle.h = m_sourceRetangle.h;

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	}
	else {
		return false;
		m_bRunning = false;
	}
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRetangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	m_sourceRetangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}