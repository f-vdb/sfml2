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

    // bequeme Methoden um oft gebrauchte Werte zu bekommen
    float x()       { return shape.getPosition().x; }
    float y()       { return shape.getPosition().y; }
    float left()    { return x() - shape.getRadius(); }
    float right()   { return x() + shape.getRadius(); }
    float top()     { return y() - shape.getRadius(); }
    float bottom()  { return y() + shape.getRadius(); }

    // "update" den Ball: bewege den shape
    void update() { 
        shape.move(velocity); 
        // Wenn der Ball links aus dem Bild geht,
        // wird die horizontale Geschwindigkeit in einen
        // positiven Wert umgewandelt (positiv nach rechts)
        if(left() < 0) velocity.x = ballVelocity;

        // Wenn der Ball rechts aus dem Bild geht,
        // wird die horizontale Geschwindigkeit in einen
        // negativen Wert umgewandelt (negativ nach links)
        else if(right() > windowWidth) velocity.x = -ballVelocity;

        // Das gleiche fuer oben und unten
        if(top() < 0) velocity.y = ballVelocity;
        else if(bottom() > windowHeigth) velocity.y = -ballVelocity;
    
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
        // bei jeder game-loop update den ball
        ball.update();
        window.draw(ball.shape);
        window.display();
    }
}


    
