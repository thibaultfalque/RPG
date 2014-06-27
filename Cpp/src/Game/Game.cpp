#include "Game.hpp"


Game::Game(Evenement & e):_event(e)
{
    _viewGame.setViewport(FloatRect(0.1,0,0.8,0.85));
    _viewMain.setViewport(FloatRect(0.f,0.f,1.f,1.f));
    _cursor.setTexture(*Ressources::getTexture("res/images/cursor2.png"));
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.setView(_viewGame);
    target.draw(_sol,states);
    target.setView(_viewMain);
    target.draw(_cursor,states);
}

void Game::onEvent(sf::Event & event){
    if (event.type == sf::Event::Resized){
        _viewGame.setSize(   event.size.width*_viewMain.getViewport().width,
                            event.size.height*_viewMain.getViewport().height);
        _viewMain.setSize(event.size.width,event.size.height);
        _viewMain.setCenter(event.size.width/2,event.size.height/2);
        _viewGame.setCenter(event.size.width/2,event.size.height/2);

    }

    if(event.type == sf::Event::MouseMoved){
        _cursor.setPosition(event.mouseMove.x,event.mouseMove.y);
    }
    if (event.type == sf::Event::MouseWheelMoved)
    {
       _viewGame.zoom(1-(event.mouseWheel.delta/10.0));
    }
}

void Game::update(sf::Time elapsedTime){
    float v = 300 * elapsedTime.asSeconds();
    if(_event.getEventState("Droite"))
        _viewGame.move(v,0);
    if(_event.getEventState("Gauche"))
        _viewGame.move(-v,0);
    if(_event.getEventState("Haut"))
        _viewGame.move(0,-v);
    if(_event.getEventState("Bas"))
        _viewGame.move(0,v);
}

Game::~Game(){}
