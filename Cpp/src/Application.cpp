#include "Application.hpp"


using namespace std;
using namespace sf;

Application::Application()
{
    _window.setFramerateLimit(60);
    _window.setKeyRepeatEnabled(false);
    _window_setting.depthBits = 24;
    _window_setting.antialiasingLevel = 8;
    _window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), L"RPG", Style::Close | Style::Titlebar | Style::Resize, _window_setting);
    _states.push_back(new Game(_event));
   _gameState = _states.size()-1;
   _window.setMouseCursorVisible(false);


}
Application::~Application(){
    for(unsigned int i=0;i<_states.size();++i)
        delete _states[i];
}

void Application::run()
{
    while(_window.isOpen())
    {
        event();
        update();
        render();
    }
}

void Application::event()
{
    Event event;
    while (_window.pollEvent(event))
    {
        switch(event.type)
        {
        case Event::Closed:
            _window.close();
            break;
        default:break;

        }
        _states[_gameState]->onEvent(event);
    }
}

void Application::update()
{
    _states[_gameState]->update(_appTimer.getElapsedTime());
   // cout << 1/_appTimer.getElapsedTime().asSeconds() << endl;
    _appTimer.restart();
}

void Application::render()
{
    _window.clear();
    _window.draw(*(_states[_gameState]));
    _window.display();
}


