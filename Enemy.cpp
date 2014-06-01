#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(Level *lev): Sprite(level){

}


Enemy::~Enemy()
{
}

void Enemy::simulateAi() {


	sf::Vector2f opponents_distance = sf::Vector2f(500,500);//calculateDistance(sprite);

	//float opp_x = sprite->getX();
	//float opp_y = sprite->getY();
	

	float mag = sqrt(
		(opponents_distance.x * opponents_distance.x) + (opponents_distance.y * opponents_distance.y));

		opponents_distance.x = opponents_distance.x / (mag);
		opponents_distance.y = opponents_distance.y / (mag);

		if (!move(opponents_distance.x, opponents_distance.y)) {

			while (!move(rand() % 3 - 1, rand() % 3 - 1)) {

			}
		}
}

