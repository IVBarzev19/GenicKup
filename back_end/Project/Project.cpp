#include <iostream>
#include <string>
using namespace std;

struct NODE
{
    string mOccasionTitle;
    string mOccasionDescription;
    string mTags;
    string mEra;
    short int mOccasionYear = 0;
    unsigned short int mOccasionMonth = 0;
    unsigned short int mOccasionDay = 0;
    NODE* next;
    NODE* previous;
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

//incomplete
void takeInput(NODE* node)
{
  cout << "Title: ";
  cin >> node->mOccasionTitle;
  cout << "Description: ";
  cin >> node->mOccasionDescription;
  cout << "Year: ";
  cin >> node->mOccasionYear;
  cout << "Month (with numbers): ";
  cin >> node->mOccasionMonth;
  cout << "Day (with numbers): ";
  cin >> node->mOccasionDay;
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

//incomplete
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

//incomplete
void prependNode(NODE** node)
{
    NODE* newNode = new NODE;
    newNode->next = *node;
    newNode->previous = NULL;
    //node->previous = *newNode;
    *node = newNode;
}

//used for testing
void printAllNodes(NODE* node)
{
    while(node->next != NULL)
    {
        cout << node->mOccasionYear << endl;
        node = node->next;
    }
}

int main()
{
    NODE* node = new NODE;

    printAllNodes(node);


    delete node;
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