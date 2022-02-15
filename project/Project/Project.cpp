#include "front-end-functions.h"

int main()
{
	NODE* Head = new NODE;

	startApp(&Head);

	deleteAllNodes(&Head);
}