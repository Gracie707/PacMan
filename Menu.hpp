#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Menu 
{  
  private: 
    Texture texture;
    Srpite sprite;
    SoundBuffer buffer;
    Sound sound;

  public:
    Menu(const string %imagenPath, const string&soundPath);
    bool run(Render Window &window);
}
