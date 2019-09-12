#pragma once
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include <PlatformLayer.h>
#include <Camera.h>
#include <Animation.h>
#include <Timer.h>
#include <Score.h>
#include <EyeCandyEngine.h>
#include <string>
#include <iostream>
#include <GameOver.h>
#include <PitchedSound.h>


const float const_player_gravity = 0.225f;
const float const_player_start_pos_x = 180;
const float const_player_start_pos_y = 417;
const int const_left_bound = 87;
const int const_right_bound = 553;
const int const_chock_anim_trigger_bound = 140;
const float const_player_xspeed_max = 6;
const float const_player_yspeed_max = 6;
const float const_player_slowdown_delta = 0.75f;
const float const_player_accelerate_delta = 0.085f;
const float const_player_friction_delta = 0.14f;

class Player
{
private:
	bool onGround;
	Platform* curPlatform;
	EyeCandyEngine ece;
	int level;
	sf::Image cjImg;
	sf::Texture cjTx;
	sf::Sprite cjSp;
	sf::SoundBuffer soundJumpLo;
	sf::SoundBuffer soundJumpMid;
	sf::SoundBuffer soundJumpHi;
	sf::SoundBuffer soundEdge;
	sf::SoundBuffer soundFalling;
	sf::SoundBuffer soundWazup;
	sf::SoundBuffer soundYo;
	PitchedSound cjSound;
	short side;
	short jumpStrenght;
	bool accelerating;
	float xSpeed;
	float ySpeed;
	float deltaSpeed;

	int checkBoundaries();
	void collide();
	void checkCollision();
	void animationAndSound(PlatformLayer& pl);
	void move();
	void jump();

	void checkMove();
	void checkJump();
	void checkCam(PlatformLayer& pl);
	void checkCandy(sf::RenderWindow& window, PlatformLayer& pl);
	void checkGameOver(PlatformLayer& pl);
public:
	Player();
	Player(std::string filename, int startPosX); //multiplayer eventually?
	void doLogic(sf::RenderWindow& window, PlatformLayer& pl);
	void render(sf::RenderWindow& window, PlatformLayer& pl);
	void reset();
};