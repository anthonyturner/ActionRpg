#pragma once
#include "SFML\Graphics.hpp"
#include "Level.h"

class Sprite :public sf::Sprite{

public:
	Sprite(Level *lev);
	~Sprite();

	bool isValidLevelMove(float xpos, float ypos);
	bool move(float, float);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	virtual void simulateAi();
	
protected:

	sf::Vector2i source;//The x defines the animation frame and y defines the movement direction image to show (down, up, left, right)
	enum DIRECTIONS{DOWN, LEFT, RIGHT, UP};//Movement directions
	Level* level;

};

