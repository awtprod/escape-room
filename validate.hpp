/***************************************************************************************************
 * * Author: Andrew Ryan
 * * Date: 4/23/19
 * * Description: Validate.hpp is the Validate specification file.
 * ************************************************************************************************/

#ifndef VALIDATE_HPP
#define VALIDATE_HPP
#include <string>
#include <iostream>
#include <fstream>

int validInt(std::string);
int validBetween(std::string, int, int);
char isEither(char, char, char);
std::string isEither(std::string, std::string, std::string, std::string);
std::string validChoice(std::string, int);
std::string validFile(std::string);


#endif
