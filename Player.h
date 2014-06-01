#pragma once
#include "Sprite.h"

class Player : public Sprite{//Player inherits from Sprite

public:
	Player(Level *lev);
	~Player();

	void simulateAi();

private:

};

