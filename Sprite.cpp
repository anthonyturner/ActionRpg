#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite(Level *lev){

	source.x = 0;
	source.y = 0;
	level = lev;
}


Sprite::~Sprite()
{
}




/*
* @param xpos and ypos: The amount in pixels to check if is valid move
*/
bool Sprite::isValidLevelMove(float xpos, float ypos) {


	return true;
	float x_calc = nearbyintf(xpos);
	float y_calc = nearbyintf(ypos);

	sf::Vector2i tile_coordinates = level->pixelsToTileCoordinate(x_calc,
		y_calc);

	cout << tile_coordinates.x << " y " << tile_coordinates.y << endl;
	Tile*tile = level->GetTile(tile_coordinates.x, tile_coordinates.y);
	if (tile == NULL){

		return false;
	}

	std::string type = tile->getType();
	if (type == (TILE_WALL)) {
		return false;
	}

	return true;
}

bool Sprite::move(float x, float y){

	if (isValidLevelMove(x, y)){

		sf::Sprite::move(x, y);
		const sf::Texture* texture = getTexture();
	
		int width = getGlobalBounds().width;//The Sprites' width
		int height = getGlobalBounds().height;//The Sprites' height

		int frame = source.x * width;//The frame image to show
		int direction_image = source.y*height;//The direction image to show

		int size = texture->getSize().x;//The total size (width) of the texture(Spritesheet)

		if (frame >= size){//Have we reached the last frame?
		
			//Reset the frame to the first animation
			source.x = 0;
			frame = source.x * width;
		
		}
		//Display the specified portion (image) from the spritesheet.
		this->setTextureRect(sf::Rect<int>(frame, direction_image, width, height));

		source.x++;//Move to next frame
		return true;


	}

	return false;
}


void Sprite::moveUp(){

	sf::Vector2f pos = this->getPosition();
	source.y = UP;
	move(0, -6);

}

void Sprite::moveDown(){

	sf::Vector2f pos = this->getPosition();
	source.y = DOWN;
	move(0, 6);
}

void Sprite::moveLeft(){

	sf::Vector2f pos = this->getPosition();
	source.y = LEFT;
	move(-6, 0);

}

void Sprite::moveRight(){

	sf::Vector2f pos = this->getPosition();
	source.y = RIGHT;
	move(6, 0);
}

void Sprite::simulateAi(){}//Virtual/abstract function
