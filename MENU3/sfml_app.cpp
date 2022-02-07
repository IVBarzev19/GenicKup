#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
#include "Menu.h"
int main()
{
   RenderWindow window(VideoMode(1020, 600), "GenicKup");
    
   Menu menu(window.getSize().x, window.getSize().y);
   Texture logo;
   if (!logo.loadFromFile("logo.png"))
   {
       //handle error
   }
   Sprite logo1;
   logo1.setTexture(logo);
   logo1.setPosition(350, 20);
   Texture texture;
   if (!texture.loadFromFile("back.jpg"))
   {
       //handle error
   }
   Sprite background;
   background.setTexture(texture);

    while (window.isOpen())
    { 
       
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch(event.key.code) {
                case Keyboard::Up:
                    menu.MoveUp();
                    break;

                case Keyboard::Down:
                    menu.MoveDown();
                    break;

                case Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0 :
                        cout << "Add";
                        window.clear(Color::White);
                        
                        break;
                        
                    case 1:
                        cout << "Search";
                        break;
                    case 2:
                        cout << "PP";
                        window.close();
                        break;
                    }
                    break;
                }
                break;

            case Event::Closed:
                window.close();
                break;
            }
        }
        
     window.clear();
        window.draw(background);
        window.draw(logo1);
        menu.draw(window);
        window.display();
    }
        
    return 0;
}