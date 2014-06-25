#include "Game.hpp"


Game::Game()
{
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            _map[i][j]=rand_int(0,4);

    for(int i=0;i<5;i++){
        _text.push_back(sf::Texture());
        if(!_text[i].loadFromFile("res/images/test/"+to_string(i)+".png")){
            cout<<"erreur"<<endl;
            exit(1);
        }
        _text[i].setSmooth(true);
    }
}
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    sf::Sprite s;
    sf::Vector2i p(0,0);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            s.setTexture(_text[_map[i][j]]);
            s.setPosition(i*41 - j*41 + 450,j*21 + i*21 + 50);

            target.draw(s,states);
        }
}
void Game::onEvent(sf::Event & event){}
void Game::update(){}
Game::~Game(){}
