#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	void update();
	void clean() {};
};