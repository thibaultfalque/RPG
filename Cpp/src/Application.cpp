#include "Application.hpp"

#include <iostream>

using namespace std;
using namespace sf;

Application::Application()
{
    _window.setFramerateLimit(FPS_MAX);
    _window.setKeyRepeatEnabled(false);
    _window_setting.depthBits = 24;
    _window_setting.antialiasingLevel = 4;
    _window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), L"RPG", Style::Close | Style::Titlebar | Style::Resize, _window_setting);
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
    }
}

void Application::update()
{

}

void Application::render()
{
    _window.clear();

    _window.display();
}


