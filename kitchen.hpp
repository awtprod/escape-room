/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Kitchen.hpp is the Kitchen class specification file.
 * ************************************************************************************************/
 
#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include <iostream>
#include <string>
#include "space.hpp"
#include "keys.hpp"

 //starting amount of cookies stored in the kitchen
int const START_COOKIES = 5;
 
 class Kitchen: public Space
 {
    public:
		Kitchen();
		virtual std::string getMenuOption();
		virtual Keys* getInteraction();
 };
 
 #endif
