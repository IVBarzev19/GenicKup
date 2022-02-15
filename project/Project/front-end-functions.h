#pragma once
#include "back-end-functions.h"

void getBack(short int& choice);

void showDeleteLogo();

void showSearchLogo();

void showAddLogo();

void showPrintLogo();

void showEditLogo();

void showTeamLogo();

void getEditNodeDetails(NODE* node, std::string sTitle, short int& sChoice);

void getSearchByEraDetails(NODE* node);

void getSearchByTagDetails(NODE* node);

void getSearchByTitleDetails(NODE* node);

void showAddMenu(NODE** node, short int& sChoice);

void showSearchMenu(NODE* node, short int& sChoice);

void showDeleteMenu(NODE* node);

void showPrintMenu(NODE* node, short int& sChoice);

void showEditMenu(NODE* node, short int& sChoice);

void showMainMenu(NODE** node);

void startApp(NODE** node);