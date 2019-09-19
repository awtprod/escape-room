/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Game.hpp is the Game class specification file.
 * ************************************************************************************************/
 
#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <stack>
#include "keys.hpp"
#include "space.hpp"
#include "room.hpp"
#include "kitchen.hpp"
#include "outside.hpp"
#include "menu.hpp"
#include "validate.hpp"
#include "random.hpp"

//number of rooms in the space
int const NUM_ROOMS = 4;

//Number of menu options, all the possible spaces to move to plus a choice to interact with the space
int const NUM_OPTIONS = 6;

//Determine if a key or cookie
int const NOT_COOKIE = -1;

int const OFFSET = 1;
 
 class Game
 {
	 private:
		Space* currentLocation;
		Keys* masterKey;
		std::stack <Keys*> basket;
		int cookiesRemaining = 3;
		int basketSize = 2;
		int jarSize = 4;
		Outside* outdoors;
		Kitchen* kitchen;
		Room* hallway, *dining, *bedroom, *closet;
		Room* roomArray[NUM_ROOMS] = { hallway, dining, bedroom, closet };
		std::string roomNames[NUM_ROOMS] = { "Hallway", "Dining Room", "Bedroom", "Closet" };

    public:
        Game();
        void runGame();
		void spaceInteraction(Keys* key);
		void movePlayer(int, Space* newLocations[]);
		void addCookies(Keys*);
		void unlockDoor();
		std::stack <Keys*> getBasket();
		void deleteGame();
 };
 
 #endif
