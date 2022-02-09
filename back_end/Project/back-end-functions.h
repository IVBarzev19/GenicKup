#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ws;

struct NODE
{
	string mOccasionTitle = "Title not set";
	string mOccasionDescription = "Description not set";
	string mTag = "Tag not set";
	string mEra = "Era not set";
	short int mOccasionYear = 0;
	unsigned short int mOccasionMonth = 0;
	unsigned short int mOccasionDay = 0;
	NODE* next = NULL;
	NODE* prev = NULL;
};

NODE* takeInput();

string convertToLower(string str);

void navigateToBegining(NODE** node);

void navigateToEnd(NODE** node);

int countNodes(NODE* node);

void swapStrings(string& str, string& str2);

void swapInts(short int& a, short int& b);

void swapInts(unsigned short int& a, unsigned short int& b);

void swapNodes(NODE** fNode, NODE** sNode);

void sortNodesByDate(NODE** node);

void printAllNodes(NODE* node);

void assignEra(NODE* node);

void assignAllEras(NODE* node);

//not complete - must add more tags =>----------------------------------------?------------------------------------------<=
void assignTag(NODE* node);

void assignAllTags(NODE* node);

void prependNode(NODE** node);

void appendNode(NODE** node);

void deleteAllNodes(NODE** node);

void searchByTag(NODE* node, string sTag);

void searchByEra(NODE* node, string sEra);