/***************************************************************************
 * * Author: Andrew Ryan
 * * Date: 4/9/19
 * * Description: menu.cpp is the menu implementation file.
 * * This function takes an array with a menu title and options and
 * * displays them to the user. It then either quits the program or
 * * returns the user's choice.
 * ************************************************************************/

#include "menu.hpp"
#include "validate.hpp"
#include <iostream>


/***************************************************************************
 * *                        buildMenu
 * * This function takes an array with a menu title and options and
 * * displays them to the user. It then either quits the program or
 * * returns the user's choice.
 * ************************************************************************/
char buildMenu(std::string* menuOptions, int numOptions, std::string quit)
{
    //Print menu title
    std::cout << menuOptions[0] << std::endl;
    
    //Iterate through menu options
    for(int option = 1; option < numOptions; option++)
    {
        std::cout << option << ": " << menuOptions[option] << std::endl; 
    }
    
    //Add quit option for user to quit program
    std::cout << "Q: " << quit << std::endl;
    
    //Initialize variable to hold user's choice
    std::string userChoice;
    
    //Get user's choice
    std::cout << "Please select an option: ";
    
    std::cin >> userChoice;
    
    //Check that the user entered a valid choice
    userChoice = validChoice(userChoice, numOptions);
    
    char ch = userChoice[0];
    //If user's choice is 'Q', quit the program
    if(tolower(ch) == 'q')
    {
        return 0;
    }
    
    //Otherwise return the user's choice
    return ch;
}

/***************************************************************************
 * *                        buildOptionMenu
 * * This function takes an array with a menu title and options and
 * * displays them to the user. 
 * ************************************************************************/
char buildOptionMenu(std::string* menuOptions, int numOptions)
{
	//Print menu title
	std::cout << menuOptions[0] << std::endl;

	//Iterate through menu options
	for (int option = 1; option < numOptions; option++)
	{
		std::cout << option << ": " << menuOptions[option] << std::endl;
	}

	//Initialize variable to hold user's choice
	std::string userChoice;

	//Get user's choice
	std::cout << "Please select an option: ";

	std::cin >> userChoice;

	//Check that the user entered a valid choice
	userChoice = validChoice(userChoice, numOptions);

	char ch = userChoice[0];

	//Otherwise return the user's choice
	return ch;
}
