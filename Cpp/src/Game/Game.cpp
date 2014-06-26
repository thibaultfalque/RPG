#include "Game.hpp"


Game::Game(Evenement & e,RenderWindow & window):_event(e),_window(window)
{
    _viewMain = _window.getDefaultView();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    _window.setView(_viewMain);
    target.draw(_sol,states);
}

void Game::onEvent(sf::Event & event){

}

void Game::update(sf::Time elapsedTime){
    float v = 150 * elapsedTime.asSeconds();
    if(_event.getEventState("Droite"))
        _viewMain.move(v,0);
    if(_event.getEventState("Gauche"))
        _viewMain.move(-v,0);
    if(_event.getEventState("Haut"))
        _viewMain.move(0,-v);
    if(_event.getEventState("Bas"))
        _viewMain.move(0,v);
}

Game::~Game(){}
