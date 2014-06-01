#include "stdafx.h"
#include "Level.h"

enum TEXTURES {
	WALL, GRASS, ROCKS, HILL
};

Level::Level(int w, int h) {

	//entities_list = list;

	SetDimensions(w, h);
	this->width = w;
	this->height = h;
	createLoader();
	generateLevel();
}

int Level::GetHeight() {
	return height;
}

int Level::GetWidth() {
	return width;
}

void Level::SetDimensions(int w, int h) {
	//w rows
	map.resize(w);

	//Each row has h columns of null Tile pointers
	for (int i = 0; i < w; i++) {
		map.at(i).resize(h, 0);
	}
}

void Level::AddTile(int x, int y, Tile* tile) {
	map[x][y] = tile;
}

Tile* Level::GetTile(int x, int y) {

	if ((x < 0 || x > width) || y < 0 || y > height)
		return NULL;

	return map[x][y];
}

/**
* Returns a random number of tiles or negative one if an invalid argument was passed
* Limit is the max random number of tiles
* Precondition: limit is greater than zero and no more than the width/tile_width (max tiles)
*
*/
int Level::getRandomNumberRowTiles(int limit){

	if (limit <= 0)
		return -1;

	return TILE_WIDTH * (rand() % limit) + 1;
}

/**
* Returns a random number of tiles or negative one if an invalid argument was passed
* Limit is the max random number of tiles
* Precondition: limit is greater than zero and no more than the height/tile_height (max tiles)
*
*/
int Level::getRandomNumberColTiles(int limit){

	if (limit <= 0 || limit > height / TILE_HEIGHT)
		return -1;
	return TILE_HEIGHT * (rand() % limit) + 1;
}

void Level::LoadLevel() {
	//Eventually we'll write code to load level data from a
	//file, but for now we'll just make it all up.
}

void Level::createLoader() {

	sf::Texture texture;

	if (texture.loadFromFile("images/wall.png")) {

		tile_image_loader.addTexture(texture);
	}

	if (texture.loadFromFile("images/grass_one.png")) {

		tile_image_loader.addTexture(texture);
	}

	if (texture.loadFromFile("images/grass_two.jpg")) {
		tile_image_loader.addTexture(texture);
	}
	if (texture.loadFromFile("images/clay.png")) {

		tile_image_loader.addTexture(texture);
	}

}

void Level::generateLevel() {

	int prob = 0;
	for (int x = 0; x < width; x++) {

		for (int y = 0; y < height; y++) {

			prob = (rand() % 100);

			//Draw wall borders - use this for houses, caves and dungeons (boxed in areas)
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1){

				map[x][y] = new Tile(TILE_WALL);

			}
			else if (prob < 95) {	//Empty space - draw non preventing space

				prob = (rand() % 100);

				if (prob > 1 && prob < 50) {

					map[x][y] = new Tile(TILE_GRASS_ONE);

				}
				else if (prob > 50 && prob < 98) {

					map[x][y] = new Tile(TILE_GRASS_TWO);

				}
				else {

					map[x][y] = new Tile(TILE_CLAY);

				}

			}
			else {	//Create a wall if 10% or less

				map[x][y] = new Tile(TILE_WALL);
			}

		}	//Inside for loop
	}
}

sf::Vector2i Level::pixelsToTileCoordinate(int x, int y){

	return sf::Vector2i(x / TILE_WIDTH, y / TILE_HEIGHT);

}


sf::Vector2i Level::tileCoordinateToPixels(int tileX, int tileY){

	return sf::Vector2i(tileX*TILE_WIDTH, tileY*TILE_HEIGHT);

}

void Level::drawLevel(sf::RenderWindow* window) {

	sf::Sprite sprite;

	for (int x = 0; x < width; x++) {

		for (int y = 0; y < height; y++) {

			Tile* tile = map[x][y];
			if (tile->getType() == (TILE_WALL)) {

				sprite.setTexture(tile_image_loader.getTexture(0));
			}
			else if (tile->getType() == (TILE_GRASS_ONE)) {

				sprite.setTexture(tile_image_loader.getTexture(1));
			}
			else if (tile->getType() == (TILE_GRASS_TWO)) {

				sprite.setTexture(tile_image_loader.getTexture(2));
			}
			else {

				sprite.setTexture(tile_image_loader.getTexture(3));
			}

			sprite.setPosition(x* TILE_WIDTH, y*TILE_HEIGHT);
			window->draw(sprite);
		}
	}
}

Level::~Level() {

}
