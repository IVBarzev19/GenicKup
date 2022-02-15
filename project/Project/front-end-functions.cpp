#include "front-end-functions.h"

void getBack(short int& choice)
{
	char answer;
	std::cout << "Do you want to continue using the application? y/n" << std::endl;
	std::cin >> answer;
	if (tolower(answer) == 'n')
	{
		choice = 7;
	}
}

void showAddLogo() {
	std::cout << "                                                ________________             ____           ____" << std::endl;
	std::cout << "                                                                            |    |         |    |" << std::endl;
	std::cout << "                                              |      ------      |          |    |         |    |" << std::endl;
	std::cout << "                                              |     |      |     |          |    |         |    |" << std::endl;
	std::cout << "                                              |     |      |     |          |    |         |    |" << std::endl;
	std::cout << "                                              |      ------      |          |    |         |    |" << std::endl;
	std::cout << "                                              |                  |          |    |         |    |" << std::endl;
	std::cout << "                                              |                  |   -------     |  -------     |" << std::endl;
	std::cout << "                                              |      ------      | |    -----    ||    -----    |" << std::endl;
	std::cout << "                                              |     |      |     | |   |     |   ||   |     |   |" << std::endl;
	std::cout << "                                              |     |      |     | |   |     |   ||   |     |   |" << std::endl;
	std::cout << "                                              |     |      |     | |    -----    ||    -----    |" << std::endl;
	std::cout << "                                               -----        -----   -------------  -------------" << std::endl;
	std::cout << " ============================================================================================================================================" << std::endl;
}

void showSearchLogo()
{
	std::cout << "                  ______________  ______________   ________________   ______________  ________________  _____         _____ " << std::endl;
	std::cout << "                  |              ||              | |                | |       ---    ||                ||     |       |     |" << std::endl;
	std::cout << "                  |              ||     --------- |      ------      ||      |   |   ||                ||     |       |     |" << std::endl;
	std::cout << "                  |      -------- |    |          |     |      |     ||      |   |   ||      ---------- |     |       |     |" << std::endl;
	std::cout << "                  |     |         |    |          |     |      |     ||       ---    ||     |           |     |       |     |" << std::endl;
	std::cout << "                  |     |         |     --------- |      ------      ||      -------- |     |           |     --------      |" << std::endl;
	std::cout << "                  |      ---------|              ||                  ||     ||   |    |     |           |                   |" << std::endl;
	std::cout << "                   -------       ||     --------- |                  ||     | |   |   |     |           |                   |" << std::endl;
	std::cout << "                          |      ||    |          |      ------      ||     |  |   |  |     |           |      -------      |" << std::endl;
	std::cout << "                   -------       ||    |          |     |      |     ||     |   |   | |      __________ |     |       |     |" << std::endl;
	std::cout << "                  |              ||     --------- |     |      |     ||     |    |   ||                ||     |       |     |" << std::endl;
	std::cout << "                  |              ||              ||     |      |     ||     |     |  ||                ||     |       |     |" << std::endl;
	std::cout << "                   --------------  --------------  -----        -----  ----        --- ----------------  -----         ----- " << std::endl;
	std::cout << " ============================================================================================================================================" << std::endl;
}

void showDeleteLogo() {
	std::cout << "                     ______________     ______________  _____            ______________  __________________  ______________ " << std::endl;
	std::cout << "                    |              -   |              ||     |          |              ||                  ||              |" << std::endl;
	std::cout << "                    |     --------   - |     --------- |     |          |     --------- |                  ||     --------- " << std::endl;
	std::cout << "                    |    |        -   ||    |          |     |          |    |           ------      ------ |    |          " << std::endl;
	std::cout << "                    |    |         |  ||    |          |     |          |    |                 |     |      |    |          " << std::endl;
	std::cout << "                    |    |         |  ||     --------- |     |          |     ---------        |     |      |     --------- " << std::endl;
	std::cout << "                    |    |         |  ||              ||     |          |              |       |     |      |              |" << std::endl;
	std::cout << "                    |    |         |  ||     --------- |     |          |     ---------        |     |      |     --------- " << std::endl;
	std::cout << "                    |    |         |  ||    |          |     |          |    |                 |     |      |    |          " << std::endl;
	std::cout << "                    |    |         -  ||    |          |     |          |    |                 |     |      |    |          " << std::endl;
	std::cout << "                    |    |       -    -|     --------- |      --------- |     ---------        |     |      |     --------- " << std::endl;
	std::cout << "                    |     -------   -  |              ||               ||              |       |     |      |              |" << std::endl;
	std::cout << "                     ---------------    --------------  ---------------  --------------         -----        -------------- " << std::endl;
	std::cout << " ============================================================================================================================================" << std::endl;
}

void showPrintLogo()
{
	std::cout << "                                      _____________  _____________   _____  _____        ____  __________________" << std::endl;
	std::cout << "                                     |             ||      ---    | |     ||     |      |    ||                  |" << std::endl;
	std::cout << "                                     |      ---    ||     |   |   | |     ||      |     |    ||                  |" << std::endl;
	std::cout << "                                     |     |   |   ||     |   |   |  ----- |       |    |    | ------      ------" << std::endl;
	std::cout << "                                     |      ---    ||      ---    |  _____ |        |   |    |       |     |" << std::endl;
	std::cout << "                                     |      ------- |         ----  |     ||         |  |    |       |     |" << std::endl;
	std::cout << "                                     |     |        |    ||   |     |     ||          | |    |       |     |" << std::endl;
	std::cout << "                                     |     |        |    | |   |    |     ||    ||     ||    |       |     |" << std::endl;
	std::cout << "                                     |     |        |    |  |   |   |     ||    | |          |       |     |" << std::endl;
	std::cout << "                                     |     |        |    |   |   |  |     ||    |  |         |       |     |" << std::endl;
	std::cout << "                                     |     |        |    |    |   | |     ||    |   |        |       |     |" << std::endl;
	std::cout << "                                     |     |        |    |     |   ||     ||    |    |       |       |     |" << std::endl;
	std::cout << "                                      -----          ----       ---  -----  ----      -------         ----- " << std::endl;
	std::cout << " ============================================================================================================================================" << std::endl;
}

void showEditLogo()
{
	std::cout << "                                                  ______________  ______________     _____  __________________ " << std::endl;
	std::cout << "                                                 |              ||              -   |     ||                  |" << std::endl;
	std::cout << "                                                 |     --------- |     --------   - |     ||                  |" << std::endl;
	std::cout << "                                                 |    |          |    |        -   | -----  ------      ------" << std::endl;
	std::cout << "                                                 |    |          |    |         |  | _____        |     |" << std::endl;
	std::cout << "                                                 |     --------- |    |         |  ||     |       |     |" << std::endl;
	std::cout << "                                                 |              ||    |         |  ||     |       |     |" << std::endl;
	std::cout << "                                                 |     --------- |    |         |  ||     |       |     |" << std::endl;
	std::cout << "                                                 |    |          |    |         |  ||     |       |     |" << std::endl;
	std::cout << "                                                 |    |          |    |         -  ||     |       |     |" << std::endl;
	std::cout << "                                                 |     --------- |    |       -    -|     |       |     |" << std::endl;
	std::cout << "                                                 |              ||     -------   -  |     |       |     |" << std::endl;
	std::cout << "                                                  --------------  --------------     -----         -----" << std::endl;
	std::cout << " ============================================================================================================================================" << std::endl;
}

void showTeamLogo() {
	std::cout << "      ________________  ______________  _____        ____  _____  ________________  _____     _____  _____         _____  _____________" << std::endl;
	std::cout << "     |                ||              ||     |      |    ||     ||                ||     |   |     ||     |       |     ||             |" << std::endl;
	std::cout << "     |                ||     --------- |      |     |    ||     ||                ||     |  |     | |     |       |     ||      ---    |" << std::endl;
	std::cout << "     |     ----------- |    |          |       |    |    | ----- |      ---------- |     | |     |  |     |       |     ||     |   |   |" << std::endl;
	std::cout << "     |     |           |    |          |         |  |    | _____ |     |           |     ||     |   |     |       |     ||      ---    |" << std::endl;
	std::cout << "     |     |           |     --------- |          | |    ||     ||     |           |           |    |     |       |     ||      -------" << std::endl;
	std::cout << "     |     |    ------ |              ||    ||     ||    ||     ||     |           |          |     |     |       |     ||     |" << std::endl;
	std::cout << "     |     |   |      ||     --------- |    | |          ||     ||     |           |           |    |     |       |     ||     |" << std::endl;
	std::cout << "     |     |   |      ||    |          |    |  |         ||     ||     |           |     ||     |   |     |       |     ||     |" << std::endl;
	std::cout << "     |     |   |      ||    |          |    |   |        ||     ||      __________ |     | |     |  |     |       |     ||     |" << std::endl;
	std::cout << "     |       ---      ||     --------- |    |    |       ||     ||                ||     |  |     | |      -------      ||     |" << std::endl;
	std::cout << "     |                ||              ||    |     |      ||     ||                ||     |   |     ||                   ||     |" << std::endl;
	std::cout << "      ----------------  --------------  ----       ------  -----  ----------------  -----     -----  -------------------  -----" << std::endl;
	std::cout << " ============================================================================================================================================" << std::endl;
}

void printBye()
{
		std::cout << "                                     _____________    _____           _____  ______________  _____" << std::endl;
		std::cout << "                                   |     -------   | |     |         |     ||              ||     |" << std::endl;
		std::cout << "                                   |    |       |   | |     |       |     | |     --------- |     |" << std::endl;
		std::cout << "                                   |    |       |   |  |     |     |     |  |    |          |     |" << std::endl;
		std::cout << "                                   |    |       |   |   |     |   |     |   |    |          |     |" << std::endl;
		std::cout << "                                   |     -------   |     |     | |     |    |     --------- |     |" << std::endl;
		std::cout << "                                   |               |      |           |     |              ||     |" << std::endl;
		std::cout << "                                   |     --------   |      |         |      |     --------- |     |" << std::endl;
		std::cout << "                                   |    |        |   |      |       |       |    |          |     |" << std::endl;
		std::cout << "                                   |    |        |   |      |       |       |    |           -----" << std::endl;
		std::cout << "                                   |    |        |   |      |       |       |     ---------  -----" << std::endl;
		std::cout << "                                   |     --------   |       |       |       |              ||     |" << std::endl;
		std::cout << "                                    ----------------         -------         --------------  -----" << std::endl;
		std::cout << " ============================================================================================================================================" << std::endl;
}

void showAboutUsMenu(short int& choice)
{
	system("cls");
	showTeamLogo();
	std::cout << std::endl << std::endl;
	std::cout << "                                                                 Hello!" << std::endl;
	std::cout << std::endl;
	std::cout << "                                In this menu you can see information about the developers of the application!" << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "                                                         Authors & contributors" << std::endl;
	std::cout << std::endl;
	std::cout << "                                                     Scrum Trainer-Alexander Tsachev" << std::endl;
	std::cout << std::endl;
	std::cout << "                                                      QA Engeneer-Stefan Ravninov" << std::endl;
	std::cout << std::endl;
	std::cout << "                                                     Back-end Developer-Ivan Barzev" << std::endl;
	std::cout << std::endl;
	std::cout << "                                                  Front-end Developer-Alexandar Bozhikov" << std::endl;
	std::cout << std::endl << std::endl;
	getBack(choice);

}

void getEditNodeDetails(NODE* node, std::string sTitle, short int& sChoice)
{
	navigateToBegining(&node);
	bool isFound = false;
	char choice;
	while (node != NULL)
	{
		if (convertToLower(node->mOccasionTitle) == convertToLower(sTitle))
		{
			std::cout << std::endl << "A node with this title was found : " << std::endl;
			printNode(node);
			isFound = true;
			break;
		}
		node = node->next;
	}
	if (isFound)
	{
		std::cout << "Do you want to edit this element? y/n" << std::endl;
		std::cin >> choice;
		if (choice == 'y')
		{
			editNode(node);
		}
	}
}

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

void showAddMenu(NODE** node, short int& sChoice)
{
	short int choice;
	system("cls");
	showAddLogo();
	std::cout << "What method do you want to use?" << std::endl;
	std::cout << "1. Appending" << std::endl;
	std::cout << "2. Prepending" << std::endl;
	std::cout << std::endl;
	std::cout << "3. Back to main menu" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		appendNode(node);
		std::cout << "Element added!" << std::endl;
		break;
	case 2:
		prependNode(node);
		std::cout << "Element added!" << std::endl;
		break;

	case 3: return;
		break;
	default:
		std::cout << "Incorrect input" << std::endl;
		break;
	}
	sortNodesByDate(node);
	getBack(choice);
}

void showSearchMenu(NODE* node, short int& sChoice)
{
	short int choice;
	system("cls");
	showSearchLogo();

	std::cout << "What are you searching for?" << std::endl;
	std::cout << "1. A specific era, the occasion took place in" << std::endl;
	std::cout << "2. A specific tag, the occasion has" << std::endl;
	std::cout << "3. The name of the specific occasion" << std::endl;
	std::cout << std::endl;
	std::cout << "4. Back to main menu" << std::endl;
	std::cin >> choice;
	std::cout << "Great!" << std::endl;
	switch (choice)
	{
	case 1:
		getSearchByEraDetails(node);
		break;

	case 2:
		getSearchByTagDetails(node);
		break;

	case 3:
		getSearchByTitleDetails(node);
		break;

	case 4: return;
		break;

	default:
		std::cout << "Incorrect input!" << std::endl;
		break;
	}
	getBack(sChoice);
}

void showDeleteMenu(NODE* node, short int& sChoice)
{
	short int choice;
	
	showDeleteLogo();

	std::cout << "Available delete-by functions:" << std::endl;
	std::cout << "1. Display all Nodes for one to be delete" << std::endl;
	std::cout << "2. Delete by tag" << std::endl;
	std::cout << "3. Delete by era" << std::endl;
	std::cin >> choice;


	switch (choice)
	{
	case 1:
	{
		//Displays all nodes
		std::cout << '\n'<<"Select which of the nodes shown above you want to delete";
		printAllNodes(node);
		int numOfNodeToBeDelete = 0;
		std::cin >> numOfNodeToBeDelete;
		deleteNthNode(node, numOfNodeToBeDelete);
		break;
	}
	case 2:
	{
		NODE* temp = node;
		std::string tag;
		std::cout << std::endl << "Enter what the tag of the elements you wish to delete is " << std::endl;
		std::cin >> std::ws;
		getline(std::cin, tag);
		//find the nodes with the given tag
		while (searchByTag(temp, tag) != NULL && temp != NULL)
		{
			if (temp->prev == NULL && temp->next == NULL)
			{
				std::cout << "No more nodes that can be delete were found\n\n";
				break;
			}
			std::cout << std::endl << "A node from this era was found : " << std::endl;
			printNode(temp);
			std::cout << "Do you wish to delete this node? y/n" << std::endl;
			char answer;
			std::cin >> answer;
			if (tolower(answer) == 'y')
			{
				deleteNode(node);
			}
		}
		break;
	}
	case 3:
	{
		//search by era
		NODE* temp = node;
		std::string era;
		std::cout << std::endl << "Enter what the era of the elements you wish to delete is " << std::endl;
		std::cin >> std::ws;
		getline(std::cin, era);
		//find the nodes with the given era
		while (searchByEra(temp, era) != NULL && temp != NULL)
		{
			if (temp->prev == NULL && temp->next == NULL)
			{
				std::cout << "No more nodes that can be delete were found\n\n";
				break;
			}
			std::cout << std::endl << "A node from this era was found : " << std::endl;
			printNode(temp);
			std::cout << "Do you wish to delete this node? y/n" << std::endl;
			char answer;
			std::cin >> answer;
			if (tolower(answer) == 'y')
			{
				deleteNode(node);
			}
		}
		break;
	}

	default:
		std::cout << "Incorrect input!" << std::endl;
		break;
	}
	getBack(sChoice);
}

void showPrintMenu(NODE* node, short int& sChoice)
{
	short int choice;
	std::string toSearch;
	system("cls");
	showPrintLogo();
	std::cout << "What do you want to print?" << std::endl;
	std::cout << "1. Every element from a specific era" << std::endl;
	std::cout << "2. Every element with a specific tag" << std::endl;
	std::cout << "3. Every element" << std::endl;
	std::cout << std::endl;
	std::cout << "4. Back to main menu" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		std::cout << "What is the era you are searching for?: ";
		std::cin >> std::ws;
		getline(std::cin, toSearch);
		printSpecificEraNodes(node, toSearch);
		break;
	case 2:
		std::cout << "What is the tag you are searching for?: ";
		std::cin >> std::ws;
		getline(std::cin, toSearch);
		printSpecificTagNodes(node, toSearch);
		break;
	case 3:
		printAllNodes(node);
		break;


	case 4: return;
		break;

	default:
		std::cout << "Incorrect input" << std::endl;
		break;
	}
	getBack(sChoice);
}

void showEditMenu(NODE* node, short int& sChoice)
{
	std::string toSearch;
	system("cls");
	showEditLogo();
	std::cout << "What is the name of the element you want to edit?" << std::endl;
	std::cin >> std::ws;
	getline(std::cin, toSearch);

	getEditNodeDetails(node, toSearch, sChoice);

	getBack(sChoice);
}

void showMainMenu(NODE** node)
{
	system("cls");
	showTeamLogo();
	std::cout << "                                                   --------------------------------" << std::endl;
	std::cout << "                                                                Menu   " << std::endl;
	std::cout << "                                                   --------------------------------" << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "                                                          1.Add new event" << std::endl << std::endl;
	std::cout << "                                                             2.Search" << std::endl << std::endl;
	std::cout << "                                                          3.Delete event" << std::endl << std::endl;
	std::cout << "                                                          4.Print events" << std::endl << std::endl;
	std::cout << "                                                          5.Edit elements" << std::endl << std::endl;
	std::cout << "                                                              6.Quiz" << std::endl << std::endl;
	std::cout << "                                                              7.Exit" << std::endl;
}

void startApp(NODE** node)
{
	short int choice = 0;
	while (choice != 7)
	{
		showTeamLogo();
		showMainMenu(node);
		std::cin >> choice;
		switch (choice)
		{
		case 1: showAddMenu(node, choice);
			break;

		case 2: showSearchMenu(*node, choice);
			break;

		case 3: showDeleteMenu(*node, choice);
			break;

		case 4: showPrintMenu(*node, choice);
			break;

		case 5: 
			showEditMenu(*node, choice);
			break;
		case 6:
			showAboutUsMenu(choice);
		default:
			std::cout << "Incorrect input!" << std::endl;
			break;
		}
	}
	system("cls");
	printBye();
}

//std::cout << "============================================================================================================================================" << std::endl;