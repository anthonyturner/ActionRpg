#ifndef ACTIONRPG_H_
#define ACTIONRPG_H_

#define GAME_WINDOW_WIDTH 1024
#define GAME_WINDOW_HEIGHT 768
#define GAME_WINDOW_TITLE "ActionRpg"

#define PLAYER_SPRITE_SHEET "images/player_sprite_sheet.png"
#define ENEMY_SPRITE_SHEET "images/enemy_sprite_sheet.png"
#define ERROR_LOADING_SPRITE_SHEET "Couldn't load sprite sheet"

#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class ActionRpg{

public:
	ActionRpg();
	~ActionRpg();

	void start();
	
	

private:

	sf::RenderWindow* window;
	Player* player;
	vector<Enemy*> enemies_list;

	map<string, sf::Texture> texture_map_list;
	
	Level* currentLevel;
	//TileMap tmap;

	bool mouseDown;
	int fps_count;
	int lastTime;

	//Camera* camera;

	//ImageLoader entities_image_loader;
	//ImageLoader player_image_manager;


	std::vector<Sprite*> entities_list;
	void initWindow();
	bool loadTextures();
	void handleEvents();
	
	void update();
	void updateSprites();
	void updateEnemies();
	void checkCollisions();
	bool fpsUpdate();

	void render();
	void drawLevel();
	void drawSprites();
	void drawEnemies();
	void drawNpcs();

	void loadImages();
	void handleMousePresses(sf::Event&);
	
	void createLoaders();
	void createLevel(string);
	void createSprites();
	void createEnemies();
	void createNPCs();
	void handleKeyPresses(sf::Event&);
};



#endif