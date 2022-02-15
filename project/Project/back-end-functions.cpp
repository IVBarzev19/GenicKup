#include "back-end-functions.h"

// ==============================> Helping functions for basic operations (printing, swaping etc.)
NODE* takeInput()
{
	NODE* node = new NODE;
	std::cout << "Title: ";
	std::cin >> std::ws;
	std::getline(std::cin, node->mOccasionTitle);
	std::cout << "Description: ";
	std::cin >> std::ws;
	std::getline(std::cin, node->mOccasionDescription);
	std::cout << "Year: ";
	std::cin >> node->mOccasionYear;
	std::cout << "Month (with numbers): ";
	std::cin >> node->mOccasionMonth;
	std::cout << "Day (with numbers): ";
	std::cin >> node->mOccasionDay;
	return node;
}

std::string convertToLower(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

void navigateToBegining(NODE** node)
{
	while ((*node)->prev != NULL && *node != NULL)
	{
		*node = (*node)->prev;
	}
}

void navigateToEnd(NODE** node)
{
	while ((*node)->next != NULL)
	{
		*node = (*node)->next;
	}
}

void swapStrings(std::string& str, std::string& str2)
{
	std::string temp = str;
	str = str2;
	str2 = temp;
}

void swapInts(short int& a, short int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapInts(unsigned short int& a, unsigned short int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapNodes(NODE** fNode, NODE** sNode)
{
	swapStrings((*fNode)->mOccasionTitle, (*sNode)->mOccasionTitle);
	swapStrings((*fNode)->mOccasionDescription, (*sNode)->mOccasionDescription);
	swapInts((*fNode)->mOccasionYear, (*sNode)->mOccasionYear);
	swapInts((*fNode)->mOccasionMonth, (*sNode)->mOccasionMonth);
	swapInts((*fNode)->mOccasionDay, (*sNode)->mOccasionDay);
}

int countNodes(NODE* node)
{
	navigateToBegining(&node);
	int i;

	for (i = 0; node != NULL; i++)
	{
		node = node->next;
	}

	return i;
}

void printNode(NODE* node)
{
	std::cout << "Title: " << node->mOccasionTitle << std::endl;
	std::cout << "Description: " << node->mOccasionDescription << std::endl;
	std::cout << "Year: " << node->mOccasionYear << std::endl;
	std::cout << "Month: " << node->mOccasionMonth << std::endl;
	std::cout << "Day: " << node->mOccasionDay << std::endl;
	std::cout << "Tag: " << node->mTag << std::endl;
	std::cout << "Era: " << node->mEra << std::endl;
	std::cout << std::endl;
}

void printAllNodes(NODE* node)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		printNode(node);
		node = node->next;
	}
}

void printSpecificEraNodes(NODE* node, std::string sEra)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		if(convertToLower(node->mEra) == convertToLower(sEra))
			printNode(node);
		node = node->next;
	}
}

void printSpecificTagNodes(NODE* node, std::string sTag)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		if (convertToLower(node->mTag) == convertToLower(sTag))
			printNode(node);
		node = node->next;
	}
}

// ==============================> Application functionality (searching, sorting etc.)
void sortNodesByDate(NODE** node)
{
	for (int i = 0; i < countNodes(*node); i++)
	{
		navigateToBegining(node);
		for (int j = 0; j < countNodes(*node) - i - 1; j++)
		{
			if ((*node)->next == NULL)
			{
				break;
			}
			if ((*node)->mOccasionYear > (*node)->next->mOccasionYear)
			{
				swapNodes(node, &(*node)->next);
			}
			else if ((*node)->mOccasionYear == (*node)->next->mOccasionYear)
			{
				if ((*node)->mOccasionMonth > (*node)->next->mOccasionMonth)
				{
					swapNodes(node, &(*node)->next);
				}
				else if ((*node)->mOccasionMonth == (*node)->next->mOccasionMonth)
				{
					if ((*node)->mOccasionDay > (*node)->next->mOccasionDay)
					{
						swapNodes(node, &(*node)->next);
					}
				}
			}
			*node = (*node)->next;
		}
	}
}

void assignEra(NODE* node)
{
	if (node->mEra == "Era not set")
	{

		if (node->mOccasionYear != 0)
		{
			if (node->mOccasionYear < -1200)
			{
				node->mEra = "Prehistory";
			}
			else if (node->mOccasionYear < 600)
			{
				node->mEra = "Classical era";
			}
			else if (node->mOccasionYear < 1500)
			{
				node->mEra = "Middle ages";
			}
			else if (node->mOccasionYear < 1815)
			{
				node->mEra = "Early modern era";
			}
			else
			{
				node->mEra = "Modern era";
			}
		}
	}
}

void assignAllEras(NODE* node)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		assignEra(node);
		node = node->next;
	}
}

//not complete - must add more tags
void assignTag(NODE* node)
{
	if (node->mTag == "Tag not set")
	{
		if (convertToLower(node->mOccasionTitle).find("conquer") != std::string::npos ||
			convertToLower(node->mOccasionTitle).find("conquest") != std::string::npos ||
			convertToLower(node->mOccasionTitle).find("battle") != std::string::npos ||
			convertToLower(node->mOccasionTitle).find("fought") != std::string::npos ||
			convertToLower(node->mOccasionTitle).find("siege") != std::string::npos ||
			convertToLower(node->mOccasionTitle).find("defeat") != std::string::npos)
		{
			node->mTag = "battle";
		}
		else
			if (convertToLower(node->mOccasionTitle).find("contract") != std::string::npos ||
				convertToLower(node->mOccasionTitle).find("sign") != std::string::npos ||
				convertToLower(node->mOccasionTitle).find("treaty") != std::string::npos)
			{
				node->mTag = "treaty";
			}
			else
				if (convertToLower(node->mOccasionTitle).find("uprising") != std::string::npos ||
					convertToLower(node->mOccasionTitle).find("rose") != std::string::npos ||
					convertToLower(node->mOccasionTitle).find("rise") != std::string::npos)
				{
					node->mTag = "uprising";
				}
				else
				{
					if (node->mTag == "Tag not set")
					{
						std::cout << "Program was unable to set tag automatically for occasion " << node->mOccasionTitle << ", please do so manually..." << std::endl;
						std::cout << "Tag: ";
						std::cin >> std::ws;
						getline(std::cin, node->mTag);
					}
				}
	}
	else
		return;
}

void assignAllTags(NODE* node)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		assignTag(node);
		node = node->next;
	}
}

void prependNode(NODE** node)
{
	navigateToBegining(node);

	NODE* newNode = new NODE;
	newNode = takeInput();
	newNode->next = *node;
	newNode->prev = NULL;
	(*node)->prev = newNode;
	navigateToBegining(node);
	assignTag(newNode);
	assignEra(newNode);
}

void addByDate(NODE** node)
{
	prependNode(node);
	sortNodesByDate(node);
}

void appendNode(NODE** node)
{
	navigateToEnd(node);

	NODE* newNode = new NODE;
	newNode = takeInput();
	newNode->next = NULL;
	newNode->prev = *node;
	(*node)->next = newNode;
	assignTag(newNode);
	assignEra(newNode);

	navigateToBegining(node);
}

void editNode(NODE* node)
{
	short int choice;
	char confirm;
	std::string str;
	short int temp;
	std::cout << "What do you want to edit?" << std::endl;
	std::cout << "1. Title" << std::endl;
	std::cout << "2. Description" << std::endl;
	std::cout << "3. Year" << std::endl;
	std::cout << "4. Month" << std::endl;
	std::cout << "5. Day" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		std::cout << "Enter the new title: " << std::endl;
		std::cin >> std::ws;
		getline(std::cin, str);
		std::cout << "Confirm change? y/n" << std::endl;
		std::cout << node->mOccasionTitle << " -> " << str << std::endl;
		std::cin >> confirm;
		if (confirm == 'y')
		{
			node->mOccasionTitle = str;
		}
		break;

	case 2:
		std::cout << "Enter the new description: " << std::endl;
		std::cin >> std::ws;
		getline(std::cin, str);
		std::cout << "Confirm change? y/n" << std::endl;
		std::cout << node->mOccasionDescription << " -> " << str << std::endl;
		std::cin >> confirm;
		if (confirm == 'y')
		{
			node->mOccasionDescription = str;
		}
		break;

	case 3:
		std::cout << "Enter the new year: " << std::endl;
		std::cin >> temp;
		std::cout << "Confirm change? y/n" << std::endl;
		std::cout << node->mOccasionYear << " -> " << temp << std::endl;
		std::cin >> confirm;
		if (confirm == 'y')
		{
			node->mOccasionYear = temp;
		}
		break;

	case 4:
		std::cout << "Enter the new month: " << std::endl;
		std::cin >> temp;
		std::cout << "Confirm change? y/n" << std::endl;
		std::cout << node->mOccasionMonth << " -> " << temp << std::endl;
		std::cin >> confirm;
		if (confirm == 'y')
		{
			node->mOccasionMonth = temp;
		}
		break;

	case 5:
		std::cout << "Enter the new day: " << std::endl;
		std::cin >> temp;
		std::cout << "Confirm change? y/n" << std::endl;
		std::cout << node->mOccasionDay << " -> " << temp << std::endl;
		std::cin >> confirm;
		if (confirm == 'y')
		{
			node->mOccasionDay = temp;
		}
		break;

	default:
		std::cout << "Incorrect input!" << std::endl;
		break;
	}
}

void searchByTag(NODE* node, std::string sTag)
{
	navigateToBegining(&node);

	bool hasFound = false;

	while (node != NULL)
	{
		if (node->mTag.find(sTag) != std::string::npos)
		{
			std::cout << std::endl << "A node with this tag was found : ";
			printNode(node);
			hasFound = true;
			break;
		}
		node = node->next;
	}
	
	if (!hasFound)
	{
		std::cout << "No such node was found!" << std::endl;
	}
}

void searchByEra(NODE* node, std::string sEra)
{
	navigateToBegining(&node);

	bool hasFound = false;

	while (node != NULL)
	{
		if (convertToLower(node->mEra).find(convertToLower(sEra)) != std::string::npos)
		{
			std::cout << std::endl << "A node from this era was found : ";
			printNode(node);
			hasFound = true;
			break;
		}
		node = node->next;
	}

	if (!hasFound)
	{
		std::cout << "No such node was found!" << std::endl;
	}
}

void searchByTitle(NODE* node, std::string sTitle)
{
	navigateToBegining(&node);

	bool hasFound = false;

	while (node != NULL)
	{
		if (convertToLower(node->mOccasionTitle) == convertToLower(sTitle))
		{
			std::cout << std::endl << "A node with this title was found : " << std::endl;
			printNode(node);
			hasFound = true;
			break;
		}
		node = node->next;
	}

	if (!hasFound)
	{
		std::cout << "No such node was found!" << std::endl;
	}
}

// ==============================> Deleting functions
void deleteNthNode(NODE*& node, int n)
{

	if (n == 1)
	{
		node = deleteFirstNode(node);
		return;
	}

	NODE* temp = node;

	for (int i = 1; i < n; i++)
	{
		temp = temp->next;
		if (temp == NULL)
			return;
	}

	NODE* privNode = temp->prev;
	NODE* nixtNode = temp->next;
	delete temp;

	privNode->next = nixtNode;
	if (nixtNode)
		nixtNode->prev = privNode;
}

NODE* deleteFirstNode(NODE* node)
{
	if (node == NULL)
		return NULL;

	NODE* temp = new NODE;
	temp = node;
	node = node->next;
	node->prev = NULL;

	delete temp;
	return node;
}


void deleteAllNodes(NODE** node)
{
	navigateToBegining(node);

	while ((*node)->next != NULL && (*node)->prev != NULL)
	{
		*node = (*node)->next;
		delete ((*node)->prev);
	}
	delete* node;
}