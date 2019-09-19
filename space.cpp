/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Space.cpp is the Space class implementation file.
 * ************************************************************************************************/
 
 #include "space.hpp"


/***************************************************************************************************
 * *                                        getSpaceName()
 * * This function gets the name of the space.
 * ************************************************************************************************/
std::string Space::getSpaceName()
{
	return spaceName;
}

/***************************************************************************************************
 * *                                        setNeighbors()
 * * This function sets the neighbors for a certain space.
 * ************************************************************************************************/
void Space::setNeighbors(Space* topIn, Space* bottomIn, Space* leftIn, Space* rightIn)
{
	top = topIn;
	bottom = bottomIn;
	left = leftIn;
	right = rightIn;
}

/***************************************************************************************************
 * *                                        getTop()
 * * This function returns the link to the top space.
 * ************************************************************************************************/
Space* Space::getTop()
{
	return top;
}

/***************************************************************************************************
 * *                                        getBottom()
 * * This function returns the link to the bottom space.
 * ************************************************************************************************/
Space* Space::getBottom()
{
	return bottom;
}

/***************************************************************************************************
 * *                                        getLeft()
 * * This function returns the link to the left space.
 * ************************************************************************************************/
Space* Space::getLeft()
{
	return left;
}

/***************************************************************************************************
 * *                                        getRight()
 * * This function returns the link to the right space.
 * ************************************************************************************************/
Space* Space::getRight()
{
	return right;
}

/***************************************************************************************************
 * *                                        getKey()
 * * This function returns key for the space.
 * ************************************************************************************************/
Keys* Space::getKey()
{
	return key;
}

/***************************************************************************************************
 * *                                        deleteKey()
 * * This function deletes the key for the space.
 * ************************************************************************************************/
void Space::deleteKey()
{
	key = nullptr;
}