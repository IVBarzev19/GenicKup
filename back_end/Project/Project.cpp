#include "back-end-functions.h"

//void addByDate()

//void editNode()

int main()
{
	NODE* Head = new NODE;

	Head = takeInput();

	assignAllTags(Head);
	assignAllEras(Head);

	printAllNodes(Head);

	deleteAllNodes(&Head);
}