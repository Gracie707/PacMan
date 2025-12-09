#include "Menu.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace sf;

Menu::Menu(const string &imagePath, const string &audioPath)
{
    // Cargar textura
    if (!texture.loadFromFile(imagePath))
    {
        cerr << "No se pudo cargar la imagen del menú: " << imagePath << endl;
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(texture);

    // Escalar la imagen para que quepa en la ventana
    // Suponemos ventana 1060x607
    Vector2u textureSize = texture.getSize();
    float scaleX = 1060.0f / textureSize.x;
    float scaleY = 607.0f / textureSize.y;
    float scale = min(scaleX, scaleY);
    sprite.setScale(scale, scale);

    // Centrar imagen
    float offsetX = (1060 - textureSize.x * scale) / 2;
    float offsetY = (607 - textureSize.y * scale) / 2;
    sprite.setPosition(offsetX, offsetY);

    // Cargar audio
    if (!buffer.loadFromFile(audioPath))
    {
        cerr << "No se pudo cargar el audio del menú: " << audioPath << endl;
        exit(EXIT_FAILURE);
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
