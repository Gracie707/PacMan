#include "Menu.hpp"
#include <iostream>
using namespace std;
using namespace sf;

Menu::Menu(const string& imagePath, const string& soundPath)
{
    if (!texture.loadFromFile(imagePath)) {
        cout << "Error cargando imagen del menú"<<endl;
    }
    sprite.setTexture(texture);

    if (!buffer.loadFromFile(soundPath)) {
        cout << "Error cargando audio del menú\n";
    }

    sound.setBuffer(buffer);
    sound.setLoop(true);
}

bool Menu::run(RenderWindow& window)
{
    sound.play();
    Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
                return false;
            }

            if (event.type == Event::KeyPressed) {
                sound.stop();
                return true;
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return false;
}

