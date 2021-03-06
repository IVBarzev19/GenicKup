#pragma once

#include <iostream>
#include <string>

struct NODE
{
	std::string mOccasionTitle = "Title not set";
	std::string mOccasionDescription = "Description not set";
	std::string mTag = "Tag not set";
	std::string mEra = "Era not set";
	short int mOccasionYear = 0;
	unsigned short int mOccasionMonth = 0;
	unsigned short int mOccasionDay = 0;
	NODE* next = NULL;
	NODE* prev = NULL;
};

// ==============================> Helping functions for basic operations (printing, swaping etc.)
NODE* takeInput();

std::string convertToLower(std::string str);

void navigateToBegining(NODE** node);

void navigateToEnd(NODE** node);

void swapStrings(std::string& str, std::string& str2);

void swapInts(short int& a, short int& b);

void swapInts(unsigned short int& a, unsigned short int& b);

void swapNodes(NODE** fNode, NODE** sNode);

int countNodes(NODE* node);

void printNode(NODE* node);

void printAllNodes(NODE* node);

void printSpecificEraNodes(NODE* node, std::string sEra);

void printSpecificTagNodes(NODE* node, std::string sTag);

// ==============================> Application functionality (searching, sorting etc.)
void sortNodesByDate(NODE** node);

void assignEra(NODE* node);

void assignAllEras(NODE* node);

//not complete - must add more tags
void assignTag(NODE* node);

void assignAllTags(NODE* node);

void prependNode(NODE** node);

void appendNode(NODE** node);

void editNode(NODE* node);

NODE* searchByTag(NODE* start, std::string sTag);

NODE* searchByEra(NODE* node, std::string sEra);

void searchByTitle(NODE* node, std::string sTitle);

NODE* searchNodeByPosition(NODE* node, int n);
// ==============================> Deleting functions
void deleteNthNode(NODE*& node, int n);

void deleteNode(NODE*& node);

void deleteAllNodes(NODE** node);