#include "back-end-functions.h"

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

void printAllNodes(NODE* node)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		std::cout << "Title: " << node->mOccasionTitle << std::endl;
		std::cout << "Description: " << node->mOccasionDescription << std::endl;
		std::cout << "Year: " << node->mOccasionYear << std::endl;
		std::cout << "Month: " << node->mOccasionMonth << std::endl;
		std::cout << "Day: " << node->mOccasionDay << std::endl;
		std::cout << "Tag: " << node->mTag << std::endl;
		std::cout << "Era: " << node->mEra << std::endl;
		std::cout << std::endl;
		node = node->next;
	}
}

void assignEra(NODE* node)
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

void assignAllEras(NODE* node)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		assignEra(node);
		node = node->next;
	}
}

//not complete - must add more tags =>----------------------------------------?------------------------------------------<=
void assignTag(NODE* node)
{
	if (convertToLower(node->mOccasionTitle).find("conquer") != std::string::npos ||
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
				std::cout << "Program was unable to set tag automatically for occasion " << node->mOccasionTitle << ", please do so manually..." << std::endl;
				std::cout << "Tag: ";
				std::cin >> node->mTag;
			}
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
}

void appendNode(NODE** node)
{
	navigateToEnd(node);

	NODE* newNode = new NODE;
	newNode = takeInput();
	newNode->next = NULL;
	newNode->prev = *node;
	(*node)->next = newNode;

	navigateToBegining(node);
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

void searchByTag(NODE* node, std::string sTag)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		if (node->mTag.find(sTag) != std::string::npos)
		{
			std::cout << std::endl << "A node with this tag was found : ";
			std::cout << node->mOccasionTitle << std::endl;
			break;
		}
		node = node->next;
	}
}

void searchByEra(NODE* node, std::string sEra)
{
	navigateToBegining(&node);

	while (node != NULL)
	{
		if (convertToLower(node->mEra).find(convertToLower(sEra)) != std::string::npos)
		{
			std::cout << std::endl << "A node from this era was found : ";
			std::cout << node->mOccasionTitle << std::endl;
			break;
		}
		node = node->next;
	}
}