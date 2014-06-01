/*
ActionRpg.cpp : Defines the entry point for the console application.
*/

#include "stdafx.h"
#include "ActionRpg.h"

ActionRpg::ActionRpg(){

	srand(time(0));
	window = new sf::RenderWindow(sf::VideoMode(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT), GAME_WINDOW_TITLE);
	if (loadTextures()){


		createLevel("");
		player = new Player(currentLevel);
		player->setPosition(0, 0);
		player->setTexture(texture_map_list.at(PLAYER_SPRITE_SHEET));
		
		int width = player->getGlobalBounds().width / 4; //TODO Assumming there are 4 frames
		int height = player->getGlobalBounds().height / 4;
		
		player->setTextureRect(sf::Rect<int>(0, 0., width, height));

		createSprites();

	}else{
	
	
		std::cout << ERROR_LOADING_SPRITE_SHEET << std::endl;
	}

}

ActionRpg::~ActionRpg(){

	delete window;
	//delete player;
}

void ActionRpg::createLevel(std::string file) {

	int num_tiles_row = GAME_WINDOW_WIDTH / 32;
	int num_tiles_col = GAME_WINDOW_HEIGHT / 32;

	currentLevel = new Level(num_tiles_row, num_tiles_col);

}

bool ActionRpg::loadTextures(){

	//load the location for each texture image
	const int size = 2;
	string textures_list[size];
	textures_list[0] = { PLAYER_SPRITE_SHEET };
	textures_list[1] = { ENEMY_SPRITE_SHEET };

	//Using one texture reference to load all textures.
	sf::Texture texture;
	//Load all textures
	for (int i = 0; i < size; i++){


		string sprite_sheet = textures_list[i];

		if (!texture.loadFromFile(sprite_sheet, sf::Rect<int>(0,0,0,0))){

			return false;

		}
		else{

			texture_map_list.insert(std::pair<string, sf::Texture>(sprite_sheet, texture));
			
		}

	}

	return true;
}

void ActionRpg::createSprites(){

	createEnemies();
}

void ActionRpg::createEnemies(){

	const int size = 5;
	//Enemy* enemies_list[size];

	for (int i = 0; i < size; i++){

		Enemy* enemy = new Enemy(currentLevel);
		int x = rand() % GAME_WINDOW_WIDTH;
		int y = rand() % GAME_WINDOW_HEIGHT;
		enemy->setPosition(x, y);

		enemy->setTexture(texture_map_list.at(ENEMY_SPRITE_SHEET));

		int width = enemy->getGlobalBounds().width / 9; //TODO Assumming there are 4 frames
		int height = enemy->getGlobalBounds().height / 8;

		enemy->setTextureRect(sf::Rect<int>(0, 0., width, height));
		enemies_list.push_back( enemy );

	}

}

//Starts the game
void ActionRpg::start(){

	while (window->isOpen()){

		update();
		render();
		handleEvents();
	}


}

//Updates all game objects
void ActionRpg::update(){

	updateSprites();
}

void ActionRpg::updateSprites(){


	updateEnemies();
}

void ActionRpg::updateEnemies(){

	for (vector<Enemy*>::iterator it = enemies_list.begin(); it != enemies_list.end(); it++){

		(*it)->simulateAi();
	}

}

//Draws all game objects
void ActionRpg::render(){

	window->clear();
	drawSprites();
	window->display();



}

void ActionRpg::drawSprites(){
	
	currentLevel->drawLevel(window);
	window->draw(*player);
	drawEnemies();


}

void ActionRpg::drawEnemies(){

	for (vector<Enemy*>::iterator it = enemies_list.begin(); it != enemies_list.end(); it++){

		window->draw((**it));
	}


}

//Handles all game events eg. Mouse and Window click events.
void ActionRpg::handleEvents(){

	sf::Event event;

	//Loop through and process all events 
	while (window->pollEvent(event)){

		//The user closed the window
		if (event.type == sf::Event::Closed){

			window->close();
		}

		handleKeyPresses(event);
		handleMousePresses(event);
	}

}

void ActionRpg::handleKeyPresses(sf::Event& event){


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ){

		player->moveLeft();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

		player->moveRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

		player->moveUp();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

		player->moveDown();
	}

}

void ActionRpg::handleMousePresses(sf::Event&){

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

		player->moveLeft();
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){

		player->moveRight();
	}

}
