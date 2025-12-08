#include "Main.hpp"
using namespace std;
using namespace sf;

Map::Map(int cellSize) : cellSize(cellSize) {}


void Map::load(vector <string> &skecth)
{  this-> skecth = skecth;
}

void Map::draw()
{  int x = 0, y=0; //fila y, columna x
   for(y = 0 ; y < skecth.size() ; y++)
   {  for(x=0; x < skecth[y].size() ; x++)
      {
        char c = skect[y][x];
        
        if( c == '#')
        {
          RectangleShape Wall(Vector2f(cellSize,cellSize));
           wall.setPosition(x * cellSize, y * cellSize);
           wall.setFillColor(Color::Blue);
           window.draw(wall);
        }
        else if (c == '.')
        {
            CircleShape pellet(Vector2f(cellSize/8)); 
            pellet.setPosition(
              x * cellSize + cellSize/2 - pellet.getRadius(),
              y * cellSize + cellSize/2 - pellet.getRadius(),
              );
            pellet.setFillColor(Color::White);
            window.draw(pellet);
        }
        else if (c == 'o')
        {  
          CircleShape pellet(Vector2f(cellSize/4)); 
            pellet.setPosition(
              x * cellSize + cellSize/2 - pellet.getRadius(),
              y * cellSize + cellSize/2 - pellet.getRadius()
              );
            pellet.setFillColor(Color::Yellow);
            window.draw(pellet);
        }
        else if(c == 'P')
        {  
          CircleShape pacman(Vector2f(cellSize/2)); 
            pacman.setPosition(x * cellSize, y * cellSize);
            pacman.setFillColor(Color::Yellow);
            window.draw(pacman);
        }
      }
   }
}
          
       

