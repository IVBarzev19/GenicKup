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
NODE* takeInput()
{
    NODE* node = new NODE;
    cout << "Title: ";
    cin >> ws;
    getline(cin, node->mOccasionTitle);
    cout << "Description: ";
    cin >> ws;
    getline(cin, node->mOccasionDescription);
    cout << "Year: ";
    cin >> node->mOccasionYear;
    cout << "Month (with numbers): ";
    cin >> node->mOccasionMonth;
    cout << "Day (with numbers): ";
    cin >> node->mOccasionDay;
    return node;
}

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
void navigateToBegining(NODE** node)
{
    while ((*node)->prev != NULL && *node != NULL)
    {
        *node = (*node)->prev;
    }
}

//working
void navigateToEnd(NODE** node)
{
    while ((*node)->next != NULL)
    {
        *node = (*node)->next;
    }
}

//working
int countNodes(NODE* node)
{
    navigateToBegining(&node);
    int i;

    for (i = 1; node->next != NULL; i++)
    {
        node = node->next;
    }

    return i;
}

//working
void swapStrings(string &str, string &str2)
{
    string temp = str;
    str = str2;
    str2 = temp;
}

//working
void swapInts(short int& a, short int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//working
void swapInts(unsigned short int& a, unsigned short int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//working
void swapNodes(NODE** fNode, NODE** sNode)
{
    swapStrings((*fNode)->mOccasionTitle, (*sNode)->mOccasionTitle);
    swapStrings((*fNode)->mOccasionDescription, (*sNode)->mOccasionDescription);
    swapInts((*fNode)->mOccasionYear, (*sNode)->mOccasionYear);
    swapInts((*fNode)->mOccasionMonth, (*sNode)->mOccasionMonth);
    swapInts((*fNode)->mOccasionDay, (*sNode)->mOccasionDay);
}

//working
void printAllNodes(NODE* node)
{
    navigateToBegining(&node);

    while (node != NULL)
    {
        cout << "Title: " << node->mOccasionTitle << endl;
        cout << "Description: " << node->mOccasionDescription << endl;
        cout << "Year: " << node->mOccasionYear << endl;
        cout << "Month: " << node->mOccasionMonth << endl;
        cout << "Day: " << node->mOccasionDay << endl;
        cout << endl;
        node = node->next;
    }
}

//working
void assignEra(NODE* node)
{
    if (node->mOccasionYear != 0)
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
    else
    {
        node->mEra = "Era not set";
    }
}

//working
void assignAllEras(NODE* node)
{
    navigateToBegining(&node);

    while (node != NULL)
    {
        assignEra(node);
        node = node->next;
    }
}

//not working - must add more tags =>----------------------------------------?------------------------------------------<=
void assignTag(NODE* node)
{
    if (convertToLower(node->mOccasionTitle).find("conquer") != string::npos ||
        convertToLower(node->mOccasionTitle).find("battle") != string::npos ||
        convertToLower(node->mOccasionTitle).find("fought") != string::npos ||
        convertToLower(node->mOccasionTitle).find("siege") != string::npos ||
        convertToLower(node->mOccasionTitle).find("defeat") != string::npos)
    {
        node->mTag = "battle";
    }

    if (convertToLower(node->mOccasionTitle).find("contract") != string::npos ||
        convertToLower(node->mOccasionTitle).find("sign") != string::npos)
    {
        node->mTag = "contract";
    }
    
    //uprising tag!
}

//working
void assignAllTags(NODE* node)
{
    navigateToBegining(&node);

    while (node != NULL)
    {
        assignTag(node);
        node = node->next;
    }
}

//working
void prependNode(NODE** node)
{
    navigateToBegining(node);
    NODE* newNode = new NODE;
    newNode = takeInput();
    newNode->next = *node;
    newNode->prev = NULL;
    (*node)->prev = newNode;
    navigateToBegining(node);
}

//working
void appendNode(NODE** node)
{
    navigateToEnd(node);

    NODE* newNode = new NODE;
    newNode = takeInput();
    newNode->next = NULL;
    newNode->prev = *node;
    (*node)->next = newNode;

    navigateToBegining(node);
}

//working
void deleteAllNodes(NODE** node)
{
    navigateToBegining(node);

    while ((*node)->next != NULL && (*node)->prev != NULL)
    {
        *node = (*node)->next;
        delete ((*node)->prev);
    }
    delete* node;
}

//working
void searchByTag(NODE* node, string sTag)
{
    navigateToBegining(&node);

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

//working
void searchByEra(NODE* node, string sEra)
{
    navigateToBegining(&node);

    while (node != NULL)
    {
        if (convertToLower(node->mEra).find(convertToLower(sEra)) != string::npos)
        {
            cout << endl << "A node from this era was found : ";
            cout << node->mOccasionTitle << endl;
            break;
        }
        node = node->next;
    }
}

//create sorting function
/*void sortNodes(NODE** node)
{
    navigateToBegining(node);
    
    for (int i = 0; i < countNodes(*node); i++)
    {
        for (int j = 0; j < countNodes(*node) - i - 1; j++)
        {
            if ((*node)->mOccasionYear > (*node)->next->mOccasionYear)
            {
                
            }
        }
    }
}*/

//void deleteNode()

//void addByDate()

//void editNode()

//void search()

int main()
{
    NODE* Head = new NODE;

    deleteAllNodes(&Head);
}