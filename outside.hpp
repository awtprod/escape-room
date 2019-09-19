/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Outside.hpp is the Outside class specification file.
 * ************************************************************************************************/
 
#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP
#include <iostream>
#include <string>
#include "space.hpp"
#include "keys.hpp"
 
 class Outside: public Space
 {
	private:
		bool locked = true;
    public:
		Outside(Keys*);
		bool isLocked();
		virtual std::string getMenuOption();
		virtual Keys* getInteraction();
 };
 
 #endif
