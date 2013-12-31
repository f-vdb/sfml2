#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr int windowWidth{800}, windowHeigth{600};
constexpr float ballRadius{10.f}, ballVelocity{8.f};


struct Ball {
    // CircleShape ist eine SFML Klasse die
    // renderbare Kreise definiert
    CircleShape shape;

    // 2D Vektor der die Ballgeschwindigkeit speichert
    Vector2f velocity{-ballVelocity, -ballVelocity};


    // Konstruktor
    Ball(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(Color::White);
        shape.setOrigin(ballRadius, ballRadius);
    }

    // "update" den Ball: bewege den shape
    void update() {shape.move(velocity); }
    
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
        // bei jeder game-loop update den ball
        ball.update();
        window.draw(ball.shape);
        window.display();
    }
}


    
