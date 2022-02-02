#include <iostream>
#include <string>
using namespace std;

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

//working
string convertToLower(string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

//working
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

//not working - getline bug =>-----------------------------------------------?------------------------------------------<=
NODE* takeInput()
{
    NODE* node = new NODE;
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
    return node;
}

//not working - must add more tags =>----------------------------------------?------------------------------------------<=
void assignTags(NODE* node)
{
    if (convertToLower(node->mOccasionTitle).find("conquer") != string::npos ||
        convertToLower(node->mOccasionTitle).find("battle") != string::npos ||
        convertToLower(node->mOccasionTitle).find("fought") != string::npos ||
        convertToLower(node->mOccasionTitle).find("siege") != string::npos)
    {
        node->mTag = "battle";
    }

    if (convertToLower(node->mOccasionTitle).find("contract") != string::npos ||
        convertToLower(node->mOccasionTitle).find("sign") != string::npos)
    {
        node->mTag = "contract";
    }
    
    //revolution tag!
}

//working
void assignAllTags(NODE* node)
{
    while (node->prev != NULL)
    {
        node = node->prev;
    }

    while (node != NULL)
    {
        assignTags(node);
        node = node->next;
    }
}

//working
void prependNode(NODE** node)
{
    NODE* newNode = new NODE;
    newNode = takeInput();
    newNode->next = *node;
    newNode->prev = (*node)->prev;
    (*node)->prev = newNode;
    *node = newNode;
}

//working
void appendNode(NODE** node)
{
    while ((*node)->next != NULL)
    {
        (*node) = (*node)->next;
    }
    NODE* newNode = new NODE;
    newNode->mOccasionTitle = "The priest died";
    //newNode = takeInput();
    newNode->next = (*node)->next;
    newNode->prev = *node;
    (*node)->next = newNode;
}

//working
void print(NODE* node)
{
    while (node->prev != NULL)
    {
        node = node->prev;
    }

    while (node != NULL)
    {
        cout << node->mOccasionTitle << " - " << node->mTag << endl;
        node = node->next;
    }
}

//working
void deleteAllNodes(NODE** node)
{
    while ((*node)->prev != NULL)
    {
        *node = (*node)->prev;
    }

    while ((*node)->next != NULL)
    {
        *node = (*node)->next;
        delete ((*node)->prev);
    }
    delete* node;
}

//working
void searchNode(NODE* node, string sTag)
{
    while (node->prev != NULL)
    {
        node = node->prev;
    }

    while (node != NULL)
    {
        if (node->mTag.find(sTag) != string::npos)
        {
            cout << endl << "A node with this tag was found : ";
            cout << node->mOccasionTitle << endl;
            break;
        }
        node = node->next;
    }
}

//void addByDate()

//void editNode

//void search

//void deleteNode

int main()
{
    NODE* node = new NODE;

    node->mOccasionTitle = "Founding of Bulgaria";

    prependNode(&node);
    appendNode(&node);

    assignAllTags(node);

    print(node);

    deleteAllNodes(&node);
}