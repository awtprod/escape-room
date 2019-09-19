/***************************************************************************
 * * Author: Andrew Ryan
 * * Date: 4/3/19
 * * Description: validate.cpp is the validate implementation file.
 * * The file validates user input.
 * ************************************************************************/

#include "validate.hpp"


//Absolute minimum
int const ABS_MIN = 1;

/***************************************************************************
 * *                            validInt()
 * * This function verifies that only integers are entered by the user.
 * ************************************************************************/
int validInt(std::string theInput)
{
    int inputAsInt;
    
    /*Code is borrowed from https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
    The condition for the while loop checks whether the cin.fail flag is triggered from bad input or the end of the
    input stream has been reached or if the input contains characters other than integers */
 
    while(std::cin.fail()||  std::cin.eof() || theInput.find_first_not_of("-0123456789") != std::string::npos) {
        
        std::cout << "Error! Please enter a valid integer." << std::endl;

    //If statement is true if only integers are entered
        if( theInput.find_first_not_of("-0123456789") == std::string::npos) {
            std::cin.clear();           //Clears cin.fail flag
            std::cin.ignore(256,'\n');  //Moves past the bad input to the next line
        }

    //Prompts the user to re-enter an integer
        std::cin >> theInput; 
    }

    //Sets the data type for the string
    std:: string::size_type st;
    
    //Converts the string to an integer
    inputAsInt = std::stoi(theInput,&st);
    
    //Returns an integer back to main function
    return inputAsInt;
}

/***************************************************************************
 * *                            validBetween()
 * * This function verifies that an integer is entered between two values
 * * by the user.
 * ************************************************************************/
int validBetween(std::string input, int min, int max)
{
   
    //Verify that an integer was inputted
    int inputAsInt = validInt(input);

	//If the user's input is less than the min or more than the max,
    //prompt the user to enter a new value
    while(inputAsInt < min || inputAsInt > max)
    {

		std::cout << "Error! Please enter a value between " << min << " and " << max <<"." << std::endl;

		//If a valid value is entered, clear bad data from stream
        if(inputAsInt > min && inputAsInt < max)
        {
            std::cin.clear();           //Clears cin.fail flag
            std::cin.ignore(256,'\n');  //Moves past the bad input to the next line
        }
        
        //Prompts the user to re-enter a value
        std::cin >> input;
        
        //Verify that an integer was inputted
        inputAsInt = validInt(input);
    }
    
    return inputAsInt;
}

/***************************************************************************
 * *                            isEither()
 * * This function verifies that a user's choice is one of the two choices 
 * * for single letter choices.
 * ************************************************************************/
char isEither(char usersChoice, char oneOption, char otherOption)
{
    //If a user doesn't enter a valid choice, prompt user to enter a valid choice
    while(tolower(usersChoice) != oneOption && tolower(usersChoice) != otherOption)
    {

        std::cout << "Error! Please enter either " << oneOption << " or " << otherOption <<"." << std::endl;
        
         //If a valid value is entered, clear bad data from stream
        if(tolower(usersChoice) == oneOption || tolower(usersChoice) == otherOption)
        {
            std::cin.clear();           //Clears cin.fail flag
            std::cin.ignore(256,'\n');  //Moves past the bad input to the next line
        }
        
        //Prompts the user to re-enter a choice
        std::cin >> usersChoice;
    }
    
    return usersChoice;
}

/***************************************************************************
 * *                            isEither()
 * * This function verifies that a user's choice is one of the two choices
 * * for string choices.
 * ************************************************************************/
std::string isEither(std::string usersChoice, std::string oneOption, std::string otherOption, std::string lastOption)
{
    //If a user doesn't enter a valid choice, prompt user to enter a valid choice
    while(usersChoice != oneOption && usersChoice != otherOption && usersChoice != lastOption)
    {

        std::cout << "Error! Please enter either " << oneOption << " or " << otherOption <<"." << std::endl;
        
         //If a valid value is entered, clear bad data from stream
        if(usersChoice == oneOption || usersChoice == otherOption || usersChoice != lastOption)
        {
            std::cin.clear();           //Clears cin.fail flag
            std::cin.ignore(256,'\n');  //Moves past the bad input to the next line
        }
        
        //Prompts the user to re-enter a choice
        std::cin >> usersChoice;
    }
    
    return usersChoice;
}

/*******************************************************************************
 * *                            validChoice()
 * * This function verifies that a user's selects a valid option from the menu.
 * ****************************************************************************/
std::string validChoice(std::string usersChoice, int numOptions)
{

    //Initializes a variable to hold the numeric choices
    int choiceAsInt = 0;
    
    //Converts only integers and excludes letters and floats
    if(isdigit(usersChoice[0]) && usersChoice.find_first_of(".Qq") == std::string::npos)
    {
        //Sets the data type for the string
        std:: string::size_type st;
    
        //Converts the string to an integer
        choiceAsInt = std::stoi(usersChoice,&st);
    }
    
    /*Code is borrowed from https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
    The condition for the while loop checks whether the user enters Q or a range of values that presented as options */

    while(usersChoice.find_first_not_of("Qq") != std::string::npos && (choiceAsInt < ABS_MIN || choiceAsInt >= numOptions)) {

        
        std::cout << "Error! Please enter a valid option." << std::endl;

        //If statement is true if only valid options are entered
        if( usersChoice.find_first_not_of("Qq") == std::string::npos || (choiceAsInt > ABS_MIN && choiceAsInt < numOptions)) 
        {
            std::cin.clear();           //Clears cin.fail flag
            std::cin.ignore(256,'\n');  //Moves past the bad input to the next line
        }

        //Prompts the user to re-enter a choice
        std::cin >> usersChoice;
        
        //Converts only integers and excludes letters and floats
        if(isdigit(usersChoice[0]) && usersChoice.find_first_of(".Qq") == std::string::npos)
        {
            //Sets the data type for the string
            std:: string::size_type st;
    
            //Converts the string to an integer
            choiceAsInt = std::stoi(usersChoice,&st);
        }
    }

    return usersChoice;
}

/***************************************************************************
 * *                            validFile()
 * * This function verifies that a valid file is entered by the user.
 * ************************************************************************/
std::string validFile(std::string fileName)
{
	//initialize boolean variable as false, will set as true if the file is valid
	bool valid = false;

	//Test if the file is valid
	//code borrowed from https://stackoverflow.com/questions/27587956/how-to-check-if-a-string-has-a-valid-file-path-or-directory-path-format-in-unman
	std::ifstream file;

	file.open(fileName.c_str());

	while (file.fail())
	{
		//prompt user to enter a filename
		std::cout << "Error! Please enter a valid file." << std::endl;

		std::cin >> fileName;

		file.open(fileName.c_str());
	}

	return fileName;
}