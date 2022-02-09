#include "back-end-functions.h"

//void addByDate()

//void editNode()

int main()
{
	NODE* Head = new NODE;

	Head = takeInput();
	appendNode(&Head);

	assignAllTags(Head);
	assignAllEras(Head);

	deleteAllNodes(&Head);
}