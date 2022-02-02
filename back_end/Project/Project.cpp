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
void print(NODE* node)
{
    while (node->prev != NULL)
    {
        node = node->prev;
    }

    while (node != NULL)
    {
        cout << node->mOccasionTitle << " - " << node->mEra << endl;
        node = node->next;
    }
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
    while (node->prev != NULL)
    {
        node = node->prev;
    }

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
    while (node->prev != NULL)
    {
        node = node->prev;
    }

    while (node != NULL)
    {
        assignTag(node);
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
void searchByTag(NODE* node, string sTag)
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

//working
void searchByEra(NODE* node, string sEra)
{
    while (node->prev != NULL)
    {
        node = node->prev;
    }

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

//void addByDate()

//void editNode

//void search

//incomplete - does not delete, only notes down the node
void deleteNode(NODE* node, string sTitle)
{
    while (node->prev != NULL)
    {
        node = node->prev;
    }

    while (node != NULL)
    {
        if (convertToLower(node->mOccasionTitle).find(convertToLower(sTitle)) != string::npos)
        {
            cout << endl << "Deleting node '" << node->mOccasionTitle << "'" << endl;

            if (node->prev != NULL)
            {
                node->prev->next = node->next;
            }
            else
            {
                node->next->prev = NULL;
            }
            
            if (node->next != NULL)
            {
                node->next->prev = node->prev;
            }
            else
            {
                node->prev->next = NULL;
            }
            break;
        }
        node = node->next;
    }

}

int main()
{
    NODE* node = new NODE;

    node = takeInput();

    prependNode(&node);
    appendNode(&node);

    deleteNode(node, "The conquer of Constantinople");

    print(node);

    deleteAllNodes(&node);
}