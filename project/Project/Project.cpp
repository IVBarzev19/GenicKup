#include "front-end-functions.h"

int main()
{
	NODE* Head = new NODE;
	Head->mOccasionTitle = "Default";
	startApp(&Head);

	deleteAllNodes(&Head);
}