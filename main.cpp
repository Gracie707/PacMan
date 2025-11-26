#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    // Create the main window
    RenderWindow window(VideoMode(1060, 607), "PACMAN");
    // Load a sprite to display
    Texture texture;
    if (!texture.loadFromFile("imagenes/MENU.png")){
    	 system("echo No se pudo cargar la textura&pause");
	return EXIT_FAILURE;}
        
    Sprite sprite1(texture);
    Vector2u textureSize = texture.getSize();
    Sprite sprite2(texture);
    sprite2.setPosition(textureSize.x, 0);
	float scaleX = 1060.0f / textureSize.x;
	float scaleY = 607.0f / textureSize.y;
	float scale = std::min(scaleX, scaleY);
	sprite1.setScale(scale, scale);
	sprite2.setScale(scale, scale);
    // Create a graphical text to display
    /*Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    Text text("Hello SFML", font, 50);*/
    // Load a music to play
   	SoundBuffer buffer;
	if(!buffer.loadFromFile("audio/pacman_menus.WAV")){
	system("echo No se pudo cargar la audio&pause");
		return EXIT_FAILURE;
		}
	Sound sound;
	sound.setBuffer(buffer);
	// Variable de control para el bucle de menú
	sound.setLoop(true);
	sound.play();
	bool in_menu = true; 
	Event event;

	// BUCLE DE MENÚ: El audio se reproduce aquí hasta que se presione una tecla.
	while (window.isOpen() && in_menu)
	{
		// Procesar eventos
		while (window.pollEvent(event))
		{
			// Si la ventana se cierra, salimos
			if (event.type == Event::Closed)
			{
				window.close();
				in_menu = false;
			}
			if (event.type == Event::KeyPressed)
			{
				in_menu = false; // Salir del bucle de menú
			}
		}
		window.clear();
		window.draw(sprite1);
		window.display();
	}
	sound.stop();
    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite1);
        window.draw(sprite2);
        // Draw the string
       // window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
