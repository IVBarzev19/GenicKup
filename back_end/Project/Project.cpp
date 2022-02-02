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
void print(NODE* node)
{
    navigateToBegining(&node);

    while (node != NULL)
    {
        cout << node->mOccasionTitle << endl;
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

//there must be a problem with the next pointer
void deleteNode(NODE** node, string sTitle)
{
    navigateToBegining(node);

    while (node != NULL)
    {
        if (convertToLower((*node)->mOccasionTitle).find(convertToLower(sTitle)) != string::npos)
        {
            cout << endl << "Deleting node '" << (*node)->mOccasionTitle << "'" << endl;

            if ((*node)->prev != NULL && (*node)->next != NULL)
            {
                *node = (*node)->prev;
                (*node)->next = (*node)->next->next;
                delete (*node)->next;
                (*node)->next->prev = *node;
                return;
            }
            else if ((*node)->prev == NULL && (*node)->next != NULL)
            {
                *node = (*node)->next;
                delete (*node)->prev;
                (*node)->prev = NULL;
                return;
            }
            else if ((*node)->prev != NULL && (*node)->next == NULL)
            {
                *node = (*node)->prev;
                delete (*node)->next;
                (*node)->next = NULL;
                return;
            }
            else
            {
                delete node;
            }
        }
        *node = (*node)->next;
    }
}

//void addByDate()

//void editNode

//void search

int main()
{
    NODE* Head = new NODE;

    Head = takeInput();

    appendNode(&Head);
    appendNode(&Head);
    appendNode(&Head);

    deleteNode(&Head, "Pedal");
    
    navigateToBegining(&Head);

    print(Head);

    deleteAllNodes(&Head);
}