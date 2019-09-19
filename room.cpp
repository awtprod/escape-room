/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Room.cpp is the Room class implementation file.
 * ************************************************************************************************/
 
 #include "room.hpp"


/***************************************************************************************************
 * *                                        Room::Room()
 * * This function creates a room with the master key.
 * ************************************************************************************************/
Room::Room(std::string spaceNameIn, Keys* keyIn)
{
	spaceName = spaceNameIn;
	key = keyIn;
}

/***************************************************************************************************
 * *                                        Room::Room()
 * * This function creates a room with just the name of the space and creates a new key.
 * ************************************************************************************************/
Room::Room(std::string spaceNameIn)
{
	spaceName = spaceNameIn;
	key = new Keys();
}

/***************************************************************************************************
 * *                                        getMenuOptions()
 * * This function returns the option to retrieve the key to the player.
 * ************************************************************************************************/
std::string Room::getMenuOption()
{
	return "Pick up the key.";
}

/***************************************************************************************************
 * *                                        getInteraction()
 * * This function returns key for the space.
 * ************************************************************************************************/
Keys* Room::getInteraction()
{
	return key;
}
