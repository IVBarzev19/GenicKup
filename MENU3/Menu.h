#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#define MAX_ITEMS 3
class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem; }

private:
	int selectedItem=0;
	Font font;
	Text menu[MAX_ITEMS];

};

