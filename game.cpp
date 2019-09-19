/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: Game.cpp is the Game class implementation file.
 * ************************************************************************************************/
 
 #include "game.hpp"
 

/***************************************************************************************************
 * *                                        Game::Game()
 * * The constructor creates a Game object with the different spaces.
 * ************************************************************************************************/
Game::Game()
{
	//Create special key for the player to find that will unlock the door to the outside
	masterKey = new Keys();

	//Create outside space and save key to match with the key the user will find
	outdoors = new Outside(masterKey);

	kitchen = new Kitchen();

	//Randomly select a room to store the master key in
	int selection = randomNumber(0, NUM_ROOMS-OFFSET);

	//Initializes the different rooms
	for (int room = 0; room < NUM_ROOMS; room++)
	{
		if (room == selection)
		{
			roomArray[room] = new Room(roomNames[room], masterKey);
		}
		else
		{
			roomArray[room] = new Room(roomNames[room]);
		}
	}

	//Creates the links between the different spaces
	outdoors->setNeighbors(nullptr, roomArray[0], nullptr, nullptr);
	kitchen->setNeighbors(roomArray[0], nullptr, nullptr, roomArray[1]);
	roomArray[0]->setNeighbors(outdoors, kitchen, roomArray[3], roomArray[2]);
	roomArray[1]->setNeighbors(roomArray[2], nullptr, kitchen, nullptr);
	roomArray[2]->setNeighbors(nullptr, roomArray[1], roomArray[0], nullptr);
	roomArray[3]->setNeighbors(nullptr, nullptr, nullptr, roomArray[0]);

	//The player will start the game in the kitchen
	currentLocation = kitchen;

}

/***************************************************************************************************
 * *                                        runGame()
 * * This function is the "main" function for running the game.
 * ************************************************************************************************/
void Game::runGame()
{
	while (cookiesRemaining > 0 && currentLocation != outdoors)
	{
		std::cout << "You are in the " << currentLocation->getSpaceName() << std::endl;
		std::cout << "Cookies remaining: " << cookiesRemaining << std::endl;

		//Create an array to store the possible spaces the player can move to
		int count = 1;
		Space* newLocations[NUM_ROOMS+OFFSET];
		std::string menuOptions[NUM_OPTIONS] = { "How do you want to proceed?"};
		menuOptions[count] = currentLocation->getMenuOption();
		count++;

		//Check each direction to see if there is a space to move to, if there is, add it to the array
		if (currentLocation->getTop() != nullptr)
		{
			menuOptions[count] = currentLocation->getTop()->getSpaceName();
			newLocations[count-OFFSET] = currentLocation->getTop();
			count++;
		}

		if (currentLocation->getBottom() != nullptr)
		{
			menuOptions[count] = currentLocation->getBottom()->getSpaceName();
			newLocations[count-OFFSET] = currentLocation->getBottom();
			count++;
		}

		if (currentLocation->getLeft() != nullptr)
		{
			menuOptions[count] = currentLocation->getLeft()->getSpaceName();
			newLocations[count-OFFSET] = currentLocation->getLeft();
			count++;
		}

		if (currentLocation->getRight() != nullptr)
		{
			menuOptions[count] = currentLocation->getRight()->getSpaceName();
			newLocations[count - OFFSET] = currentLocation->getRight();
			count++;
		}

		//Create menu to allow player to either interact with space or move
		int selection = buildOptionMenu(menuOptions, count) - '0';

		if (selection == 1)
		{
			spaceInteraction(currentLocation->getInteraction());
		}
		else
		{
			movePlayer(selection, newLocations);
		}
	}

	if (cookiesRemaining == 0)
	{
		std::cout << "You died!" << std::endl;
	}
	
	else
	{
		std::cout << "You're free!" << std::endl;
	}

	deleteGame();

}

/***************************************************************************************************
 * *                                       spaceInteraction()
 * * This function interacts with the different spaces.
 * ************************************************************************************************/
void Game::spaceInteraction(Keys* key)
{
	if (key != nullptr)
	{
		if (key->getNum() == NOT_COOKIE)
		{
				//Add new key to basket
				if (basket.size() <= basketSize)
				{
					std::cout << "Adding key to basket." << std::endl;
					basket.push(key);
					currentLocation->deleteKey();
				}
				else
				{
					std::cout << "Basket is full!" << std::endl;
				}
		}
		else
		{
			if (key->getNum() == 0)
			{
				std::cout << "The cookie jar in the kitchen is empty!" << std::endl;
			}
			else if (cookiesRemaining >= jarSize)
			{
				std::cout << "Your cookie jar is full. You must eat some cookies before getting some more." << std::endl;
			}
			else
			{
				addCookies(key);
			}
		}
	}
	else
	{
		std::cout << "You've already picked up the key!" << std::endl;
	}
}

/***************************************************************************************************
 * *                                        movePlayer()
 * * This function moves the player into a new space.
 * ************************************************************************************************/
void Game::movePlayer(int choice, Space* newLocations[])
{
	if (newLocations[choice - 1] == outdoors && outdoors->isLocked())
	{
		unlockDoor();

		if (!outdoors->isLocked())
		{
			currentLocation = outdoors;

			//std::cout << "You're free!" << std::endl;
		}
	}
	else
	{
		currentLocation = newLocations[choice - 1];

		cookiesRemaining--;
	}
}

/***************************************************************************************************
 * *                                        addCookies()
 * * This function adds cookies to the player's cookie jar.
 * ************************************************************************************************/
void Game::addCookies(Keys* cookies)
{
	if (cookiesRemaining >= jarSize)
	{
		std::cout << "The jar is full. Eat some cookies and then come back!" << std::endl;
	}
	else
	{
		std::cout << "Refilling the cookie jar." << std::endl;

		while (cookiesRemaining <= jarSize && cookies->getNum() != 0)
		{
			cookiesRemaining++;
			cookies->setNum(cookies->getNum() - 1);
		}
	}
}

/***************************************************************************************************
 * *                                        unlockDoor()
 * * This function attempts to unlock the outside door with one of the user's keys.
 * ************************************************************************************************/
void Game::unlockDoor()
{
	//Try to unlock the door
	int size = basket.size();

	bool matchKey = false;

	//Check all of the keys the user has collected
	for (int count = 0; count < size; count++)
	{
		if (masterKey == basket.top())
		{
			matchKey = true;

			//unlock outside door
			if (outdoors->isLocked())
			{
				outdoors->getInteraction();
			}
			//move outside
			else
			{
				currentLocation = outdoors;
			}
		}

		//delete key
		delete basket.top();

		basket.pop();
	}

	//If none of are able to unlock the door, alert the user
	if (!matchKey)
	{
		std::cout << "None of your keys are able to unlock the door. Keep searching!" << std::endl;
	}

}

/***************************************************************************************************
 * *                                        getBasket()
 * * This function retrieves the basket the player stored their keys in.
 * ************************************************************************************************/
std::stack <Keys*> Game::getBasket()
{
	return basket;
}

/***************************************************************************************************
 * *                                        deleteGame()
 * * This function deletes the game after the simulation is over.
 * ************************************************************************************************/
void Game::deleteGame()
{

		delete kitchen->getKey();
		kitchen->deleteKey();

		delete kitchen;
		kitchen = nullptr;

		delete outdoors;
		outdoors = nullptr;

		bool foundMasterKey = false;

		for (int count = 0; count < NUM_ROOMS; count++)
		{
			if (roomArray[count]->getKey() == masterKey)
			{
				foundMasterKey = true;
			}

			delete roomArray[count]->getKey();
			roomArray[count]->deleteKey();

			delete roomArray[count];
			roomArray[count] = nullptr;
		}

		//check if any keys are left in the stack
		if (!basket.empty())
		{
			int size = basket.size();

			for (int count = 0; count < size; count++)
			{
				delete basket.top();
				basket.pop();
			}
		}
	
}