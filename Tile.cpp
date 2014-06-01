#include "stdafx.h"
#include "Tile.h"


Tile::Tile(std::string name){

	this->type = name;
}


Tile::~Tile(){

}

std::string Tile::getType(){

	return this->type;
}
