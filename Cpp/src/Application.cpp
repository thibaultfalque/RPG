#include "Application.hpp"


using namespace std;
using namespace sf;

Application::Application()
{
    _window.setFramerateLimit(FPS_MAX);
    _window.setKeyRepeatEnabled(false);
    _window_setting.depthBits = 24;
    _window_setting.antialiasingLevel = 4;
    _window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), L"RPG", Style::Close | Style::Titlebar | Style::Resize, _window_setting);
    _states.push_back(Game());
    _gameState = _states.size()-1;
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
        _states[_gameState].onEvent(event);
    }
}

void Application::update()
{
    _states[_gameState].update(_appTimer.getElapsedTime());
    _appTimer.restart();
}

void Application::render()
{
    _window.clear();
    _window.draw(_states[_gameState]);
    _window.display();
}


