#include "Menu.h"
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{
		//handle error
	}
	
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Add");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(Vector2f(width/2, height/(MAX_ITEMS+1)*1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::Black);
	menu[1].setString("Search");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::Black);
	menu[2].setString("Exsit");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

}
Menu::~Menu()
{

}
void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(Color::Black);
		selectedItem--;
		menu[selectedItem].setFillColor(Color::Red);
	}
}
void Menu::MoveDown()
{
	if (selectedItem + 1 < MAX_ITEMS)
	{
		menu[selectedItem].setFillColor(Color::Black);
		selectedItem++;
		menu[selectedItem].setFillColor(Color::Red);
	}
}