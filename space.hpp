/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Space.hpp is the Space class specification file.
 * ************************************************************************************************/
 
#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <string>
#include "keys.hpp"
 
 class Space
 {
	 protected:
		 Space* top, *bottom, *left, *right;
		 Keys* key;
		 std::string spaceName;
		 std::string messages[3];

    public:
		std::string getSpaceName();
		virtual std::string getMenuOption()=0;
		virtual Keys* getInteraction()=0;
		void setNeighbors(Space* top, Space* bottom, Space* left, Space* right);
		Space* getTop();
		Space* getBottom();
		Space* getLeft();
		Space* getRight();
		Keys* getKey();
		void deleteKey();
 };
 
 #endif
