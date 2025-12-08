#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Map
{  
  private:
    int cellSize;
    vector <string> skecth; //Vector linea del mapa

  public:
    Map(int cellSize);
    void load(const vector <string> &sketch);
    void draw(RenderWindow &window);

};




