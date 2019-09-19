/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Room.hpp is the Room class specification file.
 * ************************************************************************************************/
 
#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include <string>
#include "space.hpp"
#include "keys.hpp"
 
 class Room: public Space
 {
    public:
		Room(std::string, Keys*);
		Room(std::string);
		virtual std::string getMenuOption();
		virtual Keys* getInteraction();
 };
 
 #endif
