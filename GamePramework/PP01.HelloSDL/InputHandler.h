#pragma once
#include "SDL.h"
#include "Vector2D.h"

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	const Uint8* m_keystates;
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onMouseMove(SDL_Event event);
	void onKeyDown();
	void onKeyUp();

	Vector2D* m_mousePosition = new Vector2D(0, 0);
	Vector2D* getMousePosition();

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;