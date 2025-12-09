#include "Map.hpp"
using namespace std;
using namespace sf;

Map::Map(int cellSize) : cellSize(cellSize) {}


void Map::load(const vector <string> &sketch)
{  this-> sketch = sketch;
}

void Map::draw(RenderWindow &window)
{  
	RectangleShape wall;
	CircleShape pellet;

int x = 0, y=0; //fila y, columna x
   for(y = 0 ; y < sketch.size() ; y++)
   {  for(x=0; x < sketch[y].size() ; x++)
      {
        char c = sketch[y][x];
        
        if( c == '#')
        {
          RectangleShape wall(Vector2f(cellSize,cellSize));
           wall.setPosition(x * cellSize, y * cellSize);
           wall.setFillColor(Color::Blue);
           window.draw(wall);
        }
        else if (c == '.')
        {
            CircleShape pellet(cellSize/8.0f); 
            pellet.setPosition(
              x * cellSize + cellSize/2 - pellet.getRadius(),
              y * cellSize + cellSize/2 - pellet.getRadius()
              );
            pellet.setFillColor(Color::White);
            window.draw(pellet);
        }
        else if (c == 'o')
        {  
          CircleShape pellet(cellSize/4.0f); 
            pellet.setPosition(
              x * cellSize + cellSize/2 - pellet.getRadius(),
              y * cellSize + cellSize/2 - pellet.getRadius()
              );
            pellet.setFillColor(Color::Yellow);
            window.draw(pellet);
        }
        else if(c == 'P')
        {  
          CircleShape pacman(cellSize/2.0f); 
            pacman.setPosition(x * cellSize, y * cellSize);
            pacman.setFillColor(Color::Yellow);
            window.draw(pacman);
        }
      }
   }
}
          
       
