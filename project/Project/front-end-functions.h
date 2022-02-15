#pragma once
#include "back-end-functions.h"

void getSearchByEraDetails(NODE* node);

void getSearchByTagDetails(NODE* node);

void getSearchByTitleDetails(NODE* node);

void showSearchMenuOptions(NODE* node, short int& sChoice);

void showDeleteMenuOptions(NODE* node);

void showPrintNodesMenu(NODE* node, short int& sChoice);

void getBack(short int& choice);

void showAddMenu(NODE** node, short int& sChoice);

void showDeleteTitle();

void showSearchTitle();

void showAddTitle();

void showPrintTitle();

void showTeamTitle();

void showMenuOptions(NODE** node);

void startApp(NODE** node);