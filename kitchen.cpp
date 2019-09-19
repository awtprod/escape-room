/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Kitchen.cpp is the Kitchen class implementation file.
 * ************************************************************************************************/
 
 #include "kitchen.hpp"

/***************************************************************************************************
 * *                                        Kitchen::Kitchen()
 * * This function creates the kitchen.
 * ************************************************************************************************/
Kitchen::Kitchen()
{
	spaceName = "Kitchen";
	key = new Keys();
	key->setNum(START_COOKIES);
}

/***************************************************************************************************
 * *                                        getMenuOptions()
 * * This function returns the option to refill on cookies.
 * ************************************************************************************************/
std::string Kitchen::getMenuOption()
{
	return "Pick up some cookies.";
}

/***************************************************************************************************
 * *                                        getInteraction()
 * * This function returns key for the space.
 * ************************************************************************************************/
Keys* Kitchen::getInteraction()
{
	return key;
}
