#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include "Menu.hpp"
#include "Map.hpp"
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(1060, 607), "PACMAN");

    // --- MENU ---
    Menu menu("imagenes/MENU.png", "audio/pacman_menus.WAV");
    if (!menu.run(window))
        return 0;

    // --- MAPA ---
    vector<string> sketch = {
        "###################",
        "#........#........#",
        "#o##.###.#.###.##o#",
        "#.................#",
        "#.##.#.#####.#.##.#",
        "#....#...#...#....#",
        "####.### # ###.####",
        "#.#   0   P   1  #.#",
        "#####.# ##=## #.#####",
        "#........#........#",
        "###################"
    };

    Map map(24);
    map.load(sketch);

    // ---- GAME LOOP ----
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Black);
        map.draw(window);
        window.display();
    }

    return 0;
}
