#include "front-end-functions.h"

void getSearchByEraDetails(NODE* node)
{
	std::string toSearch;
	std::cout << "Please enter the era you are searching for: ";
	std::cin >> std::ws;
	getline(std::cin, toSearch);
	searchByEra(node, toSearch);
}

void getSearchByTagDetails(NODE* node)
{
	std::string toSearch;
	std::cout << "Please enter the tag you are searching for: ";
	std::cin >> std::ws;
	getline(std::cin, toSearch);
	searchByTag(node, toSearch);
}

void getSearchByTitleDetails(NODE* node)
{
	std::string toSearch;
	std::cout << "Please enter the occasion you are searching for: ";
	std::cin >> std::ws;
	getline(std::cin, toSearch);
	searchByTitle(node, toSearch);
}

void showSearchMenuOptions(NODE* node)
{
	short int choice;
	std::cout << "What are you searching for?" << std::endl;
	std::cout << "A specific era, the occasion took place in (0)" << std::endl;
	std::cout << "A specific tag, the occasion has           (1)" << std::endl;
	std::cout << "The name of the specific occasion          (2)" << std::endl;
	std::cin >> choice;
	std::cout << "Great!" << std::endl;
	switch (choice)
	{
	case 0:
		getSearchByEraDetails(node);
		break;

	case 1:
		getSearchByTagDetails(node);
		break;

	case 2:
		getSearchByTitleDetails(node);
		break;
	}
}