#ifndef APPLICATION_H
#define APPLICATION_H


#include "headers.hpp"

#include "Evenement.hpp"
#include "Bouton.hpp"
#include "AudioConfiguration.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

class Application
{

private:
    RenderWindow _window;
    ContextSettings _window_setting;

    AudioConfiguration _audio;
    Evenement _event;

    vector<ScreenElement*> _states;
    unsigned int _gameState;

    sf::Clock _appTimer;
private:
    void update();
    void render();
    void event();

public:
    Application();
    ~Application();

    void run();

};




#endif // APPLICATION_H
