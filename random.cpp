/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 4/23/19
 * * Description: Random.cpp is the Random implementation file. It randomly generates a number
 * * within a range of numbers.
 * ************************************************************************************************/
#include "random.hpp"

//minimum value for an array
int const MIN = 0;

//offset for array
int const OFFSET = 1;


/***************************************************************************************************
 * *                                        randomNumber()
 * * This function generates a random number based on bounds provided.
 * * Code borrowed from https://stackoverflow.com/questions/19553265/how-does-modulus-and-rand-work
 * ************************************************************************************************/
int randomNumber(int min, int max)
{
    //initializes random number generator
    std::random_device rd;

    //generates a seed for the random generator so that you don't get the 
    //same sequence of numbers each time the function is executed
    std::mt19937 e2(rd());

    //restrict the random number generator between the given minimum and maximum values
    std::uniform_int_distribution<int> dist(min, max);
    
    return dist(e2);
}

/***************************************************************************************************
 * *                                        randomString()
 * * This function selects a random string based on an array provided.
 * * Code borrowed from https://stackoverflow.com/questions/19553265/how-does-modulus-and-rand-work
 * ************************************************************************************************/
std::string randomString(std::string stringArray[], int arraySize)
{
    //initializes random number generator
    std::random_device rd;

    //generates a seed for the random generator so that you don't get the 
    //same sequence of numbers each time the function is executed
    std::mt19937 e2(rd());

    //restrict the random number generator between the given minimum and maximum values
    std::uniform_int_distribution<int> dist(MIN, arraySize-OFFSET);
    
    return stringArray[dist(e2)];
}
