#pragma once
#include "Sprite.h"
class Enemy : public Sprite{

public:
	Enemy(Level *lev);
	~Enemy();

	void simulateAi();

};

