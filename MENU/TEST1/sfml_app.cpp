#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include <windows.h>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(800, 600), "Survival Game");
    Texture background;
    Sprite backgroundImage;

    if (!background.loadFromFile("Images/back.jpg"))
        cout << "Error: Could not display Alaskan Wilderness image" << endl;

    backgroundImage.setTexture(background);

    Font font;
    if (!font.loadFromFile("font.ttf"))
       cout << "Can't find the font file" << endl;

    Texture exitButton;
    Sprite exitButtonImage;
    if (!exitButton.loadFromFile("Images/exit.jpg"))
        cout << "Can't find the image" << endl;
    exitButtonImage.setPosition(270,500);

    float exitButtonWidth = exitButtonImage.getLocalBounds().width;
    float exitButtonHeight = exitButtonImage.getLocalBounds().height;

    exitButtonImage.setTexture(exitButton);

    Texture searchButton;
    Sprite searchButtonImage;
    if (!searchButton.loadFromFile("Images/search.jpg"))
        cout << "Can't find the image" << endl;
    searchButtonImage.setPosition(240, 350);

    float searchButtonWidth = exitButtonImage.getLocalBounds().width;
    float searchButtonHeight = exitButtonImage.getLocalBounds().height;
    searchButtonImage.setTexture(searchButton);

    Texture addButton;
    Sprite addButtonImage;
    if (!addButton.loadFromFile("Images/add.jpg"))
        cout << "Can't find the image" << endl;
    addButtonImage.setPosition(280, 200);

    float addButtonWidth = addButtonImage.getLocalBounds().width;
    float addButtonHeight = addButtonImage.getLocalBounds().height;

    addButtonImage.setTexture(addButton);
    Texture backButton;
    Sprite backButtonImage;
    if (!backButton.loadFromFile("Images/backBtn.jpg"))
        cout << "Can't find the image" << endl;
    backButtonImage.setPosition(50, 500);

    float backtButtonWidth = backButtonImage.getLocalBounds().width;
    float backButtonHeight = backButtonImage.getLocalBounds().height;
    backButtonImage.setTexture(backButton);

    Texture exButton;
    Sprite exButtonImage;
    if (!exButton.loadFromFile("Images/exit1.jpg"))
        cout << "Can't find the image" << endl;
    exButtonImage.setPosition(270, 500);

    float exButtonWidth = exButtonImage.getLocalBounds().width;
    float exButtonHeight = exButtonImage.getLocalBounds().height;

    exButtonImage.setTexture(exButton);

        window.draw(backgroundImage);
        window.draw(exitButtonImage);
        window.draw(searchButtonImage);
        window.draw(addButtonImage);
        window.display();
        
    while (window.isOpen())
    {
         Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
            {
                Vector2i mousePos = Mouse::getPosition(window);
                Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (exitButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    window.close();
                }
                if (backButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    window.draw(backgroundImage);
                    window.draw(exitButtonImage);
                    window.draw(searchButtonImage);
                    window.draw(addButtonImage);
                    window.display();
                    
                }
                
                
                if (searchButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    
                    
                    window.draw(backgroundImage);
                    window.draw(exButtonImage);
                    window.draw(backButtonImage);
                    window.display();
                    
                    
                    
                }
                if (addButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    window.draw(backgroundImage);
                    window.draw(backButtonImage);
                    window.display();

                }
            }
            break;
            }
        }

       window.clear();
        
    }
    
    return 0;
}