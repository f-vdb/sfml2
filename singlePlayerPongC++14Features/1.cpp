#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr int windowWidth{800}, windowHeigth{600};

int main()
{
    // Erzeugung game window
    RenderWindow window{{windowWidth, windowHeigth}, "Single Player Pong"};
    window.setFramerateLimit(60);

    while(true)
    {
        window.clear(Color::Black);

        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

        window.display();
    }
}


    
