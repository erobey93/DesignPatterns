//Emily Robey
//CST 276 - WI 23 - Lab 2
//driver

#include <SFML/Graphics.hpp>
#include "rand.h"
#include "world.h"
#include "enemyFactory.h"
#include "ship.h"
#include "config.h"

using std:: cout;
using std:: endl;


void render(sf::RenderWindow & window, World aWorld) {

    // always clear!
    window.clear();

    // drawing happens here (off-screen)
    aWorld.render(window, sf::RenderStates::Default);

    // swap the display buffer (double-buffering)
    window.display();
}

void processEvents(sf::RenderWindow & window, World aWorld) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

int main(int argc, char* argv[]) {


    World newWorld;
    Config& c = Config::Instance(); //create instance of singleton class "Config"
    c.readIn(argv[1]);

    //create variables to hold window width and height
    const float WINDOW_WIDTH = 700;//c.width();
    const float WINDOW_HEIGHT = 1000;//c.height(); TODO --> create file with values in it and switch this to c.width(), c.height();
    sf::RenderWindow window{sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "Lab2"};


    for (int i{}; i < 10; ++i) {
        newWorld.addEntity(EnemyFactory::makeEnemy());

        newWorld.update(i, WINDOW_WIDTH);
    }

    //create ship
    newWorld.addEntity(new Ship(0, 300.f, WINDOW_HEIGHT - 550));
    newWorld.update(0, WINDOW_WIDTH);


    // for info on game loops:
    //   https://subscription.packtpub.com/book/game+development/9781849696845/1/ch01lvl1sec11/game-loops-and-frames
    sf::Clock clock;

    sf::Time t{sf::Time::Zero}; // time
    sf::Time dt{sf::seconds(1.0f / 60.0f)}; // delta time (fixed to 60fps)
    while (window.isOpen()) {

        processEvents(window,newWorld);// FIXME don't understand how to use this with world class
        t += clock.restart();
        while (t > dt) {
            t -= dt;
            processEvents(window, newWorld);
            newWorld.update(5, WINDOW_WIDTH);

            render(window,newWorld);

        }
    }
}
