#include "../include/Functions.h"

std::string Functions::convertToUpper(std::string& toConvert)
{
    std::string result = toConvert;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string Functions::convertToLower(std::string& toConvert)
{
    std::string result = toConvert;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}