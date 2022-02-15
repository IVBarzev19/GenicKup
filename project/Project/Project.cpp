#include "front-end-functions.h"

int main()
{
	NODE* Head = new NODE;
	Head->mOccasionTitle = "Fall of Constantinople";
	Head->mOccasionDescription = "The dwindling Byzantine Empire came to an end when the Ottoman ruler Sultan Mehmed II breached Constantinople's ancient land wall after besieging the city for 55 days.";
	Head->mOccasionYear = 1453;
	Head->mOccasionMonth = 5;
	Head->mOccasionDay = 29;
	Head->mEra = "Middle ages";
	Head->mTag = "battle";
	
	startApp(&Head);

	deleteAllNodes(&Head);
}