/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Outside.cpp is the Outside class implementation file.
 * ************************************************************************************************/
 
 #include "outside.hpp"

/***************************************************************************************************
 * *                                        Outside::Outside()
 * * This function creates the outdoors space.
 * ************************************************************************************************/
Outside::Outside(Keys* masterKey)
{
	spaceName = "Outdoors";
	key = masterKey;
}

/***************************************************************************************************
 * *                                        isLocked()
 * * This function returns whether or not the door is locked.
 * ************************************************************************************************/
bool Outside::isLocked()
{
	return locked;
}

/***************************************************************************************************
 * *                                        getMenuOptions()
 * * This function returns the option to either unlock the door or open it.
 * ************************************************************************************************/
std::string Outside::getMenuOption()
{
	if (locked)
	{
		return "Unlock the door.";
	}
	else
	{
		return "open door.";
	}

}

/***************************************************************************************************
 * *                                        getInteraction()
 * * This function returns whether or not the door is unlocked.
 * ************************************************************************************************/
Keys* Outside::getInteraction()
{
	if (locked)
	{
		locked = false;

		return key;
	}
	else
	{
		return key;
	}
}
