#include "front-end-functions.h"

//void addByDate()

//void editNode()

int main()
{
	NODE* Head = new NODE;

	Head->mOccasionTitle = "The conquer of Constantinople";
	/*
	Head = takeInput();
	appendNode(&Head);

	assignAllTags(Head);
	assignAllEras(Head);
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << countNodes(Head);

	std::cout << std::endl;

	printAllNodes(Head);*/
	showDeleteMenuOptions(Head);

	deleteAllNodes(&Head);

}