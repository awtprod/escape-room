/***************************************************************************
 * * Author: Andrew Ryan
 * * Date: 6/7/19
 * * Description: main.cpp is the main function file.
 * * This function allows the user to test the buffer or create a palindrome.
*******************************************************************************/

#include "game.hpp"
#include "menu.hpp"
#include "validate.hpp"
#include <iostream>
#include <fstream>
#include <string>

//Number of menu options
int const NUM_MENU_OPTIONS = 2;


int main()
{
	std::string line;

	//initialize introduction
	std::ifstream inputFile;

	//Open file
	inputFile.open("introduction.txt");

	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			std::cout << line << std::endl;
		}
		inputFile.close();
	}

	else std::cout << "Unable to open file";


    std::string menuOptions[NUM_MENU_OPTIONS] = {"Do you accept the challenge?", "Well, no one has ever told me a lie, especially on paper!"};
    
    while(char selection = buildMenu(menuOptions, NUM_MENU_OPTIONS, "Ugh! So bored! Let's go snapchat ourselves staring a random people."))
    {
		Game game;

		game.runGame();

    }

    return 0;
}