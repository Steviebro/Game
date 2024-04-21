#include <string>
#include <sstream>
#include <ctime>

#include <algorithm>


class Functions {
public:
    static std::string convertToUpper(std::string& toConvert);
    static std::string convertToLower(std::string& toConvert);
    static int rollDice(std::string diceType);
private:
    static bool isSeeded;
};