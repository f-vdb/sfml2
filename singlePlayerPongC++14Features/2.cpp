#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr int windowWidth{800}, windowHeigth{600};
constexpr float ballRadius{10.f};

struct Ball {
    // CircleShape ist eine SFML Klasse die
    // renderbare Kreise definiert
    CircleShape shape;

    // Konstruktor
    Ball(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(Color::White);
        shape.setOrigin(ballRadius, ballRadius);
    }
};


int main() {
    // Instanz der Klasse Ball
    Ball ball{windowWidth / 2, windowHeigth / 2};

    // Erzeugung game window
    RenderWindow window{{windowWidth, windowHeigth}, "Single Player Pong"};
    window.setFramerateLimit(60);

    while(true)
    {
        window.clear(Color::Black);

        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;
        window.draw(ball.shape);
        window.display();
    }
}


    
