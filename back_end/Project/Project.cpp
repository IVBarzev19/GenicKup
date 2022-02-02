#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct NODE
{
    string mOccasionTitle = "*Title*";
    string mOccasionDescription = "*Description*";
    string mTags = "*Tags*";
    string mEra = "*Era*";
    short int mOccasionYear = 0;
    unsigned short int mOccasionMonth = 0;
    unsigned short int mOccasionDay = 0;
    NODE* next = NULL;
    NODE* prev = NULL;
};

//complete
string convertToLower(string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

//complete
void assignEra(NODE* node)
{
    if (node->mOccasionYear < -1200)
    {
        node->mEra = "Prehistory";
    }
    else if (node->mOccasionYear < 600)
    {
        node->mEra = "Classical era";
    }
    else if (node->mOccasionYear < 1500)
    {
        node->mEra = "Middle ages";
    }
    else if (node->mOccasionYear < 1815)
    {
        node->mEra = "Early modern era";
    }
    else
    {
        node->mEra = "Modern era";
    }
}

//incomplete - getline bug
void takeInput(NODE* node)
{
  cout << "Title: ";
  getline(cin, node->mOccasionTitle);
  cout << "Description: ";
  getline(cin, node->mOccasionDescription);
  cout << "Year: ";
  cin >> node->mOccasionYear;
  cout << "Month (with numbers): ";
  cin >> node->mOccasionMonth;
  cout << "Day (with numbers): ";
  cin >> node->mOccasionDay;
}

//incomplete - must add more tags
void assignTags(NODE* node)
{
    if (convertToLower(node->mOccasionTitle).find("conquer") != string::npos ||
        convertToLower(node->mOccasionTitle).find("battle") != string::npos ||
        convertToLower(node->mOccasionTitle).find("fought") != string::npos ||
        convertToLower(node->mOccasionTitle).find("siege") != string::npos)
    {
        node->mTags = "battle";
    }

    if (convertToLower(node->mOccasionTitle).find("contract") != string::npos ||
        convertToLower(node->mOccasionTitle).find("sign") != string::npos)
    {
        node->mTags = "contract";
    }
}

//complete
void prependNode(NODE** node)
{
    NODE* newNode = new NODE;
    newNode->mOccasionTitle = "The fall of Constantinople";
    newNode->next = *node;
    newNode->prev = (*node)->prev;
    (*node)->prev = newNode;
    *node = newNode;
}

//complete
void appendNode(NODE** node)
{
    while ((*node)->next != NULL)
    {
        (*node) = (*node)->next;
    }
    NODE* newNode = new NODE;
    newNode->mOccasionTitle = "The 1-hundred years war";
    newNode->next = (*node)->next;
    newNode->prev = *node;
    (*node)->next = newNode;
}

//complete
void print(NODE* node)
{
    while (node->prev != NULL)
    {
        node = node->prev;
    }

    while (node != NULL)
    {
        cout << node->mOccasionTitle << endl;
        node = node->next;
    }
}

//void addByDate()

//void editNode

//void search

//void deleteNode

//complete
void deleteAllNodes(NODE** node)
{
    while ((*node)->prev != NULL)
    {
        *node = (*node)->prev;
    }

    while ((*node)->next != NULL)
    {
        *node = (*node)->next;
        cout << "Deleting ..." << endl;
        delete ((*node)->prev);
    }
    cout << "Deleting ..." << endl;
    delete* node;
}

int main()
{
    NODE* node = new NODE;

    node->mOccasionTitle = "Founding of Bulgaria";

    prependNode(&node);
    appendNode(&node);

    print(node);

    deleteAllNodes(&node);
}
































/*



void addLastElement(NODE* node)
{
  while(node->next != NULL)
  {
    node = node->next;
  }

  takeInput(node);
}

void addElementByDate(NODE* node)
{
  NODE* newNode = new NODE;
  while(node->previous != NULL)
  {
    node = node->previous;
  }

  if(node->occasionYear > newNode->occasionYear)
  {
    //doShuff;
  }
}

void search(NODE* node, int year = -9999, int month = 0, int day = 0)
{
  while(node->previous != NULL)
  {
    node = node->previous;
  }

  //doStuff;
}

void eraseElement()
{
  //find matching criteria and delete();
}

*/