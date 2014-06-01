#pragma once
#include <string>

#define TILE_WIDTH (32)
#define TILE_HEIGHT (32)

using namespace std;
class Tile{


public:
	Tile(std::string name);
	~Tile();


	std::string getType();
	//bool collides(sf::Rect<float>& );

private:

	std::string type;

};

