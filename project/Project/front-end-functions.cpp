#include "front-end-functions.h"

void showSearchMenuOptions()
{
	std::string toSearch;
	std::cout << "What are you searching for?" << std::endl;
	std::cout << "A specific era, the occasion took place in (0)" << std::endl;
	std::cout << "A specific tag, the occasion has           (1)" << std::endl;
	std::cout << "The name of the specific occasion          (2)" << std::endl;
	std::cin >> std::ws;
	getline(std::cin, toSearch);
	std::cout << "Thank you!" << std::endl;
}