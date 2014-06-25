#include "Game.hpp"


Game::Game()
{
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            _map[i][j]=rand_int(0,4);
    for(int i=0;i<5;i++){
        sf::Texture text;
        _sprite.push_back(sf::Sprite());
        if(!text.loadFromFile("res/images/test/"+to_string(i)+".png")){
            cout<<"erreur"<<endl;
            exit(1);
        }
        _sprite[i].setTexture(text);
    }
}
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    cout<<"draw"<<endl;
    /*for(int i=0;i<50;i++)
        for(int j=0;j<50;j++){
            sf::Sprite s;
            switch(_map[i][j]){
                case 0:
                    s=_sprite[0];
                    s.setPosition(s.getTexture()->getSize().x*i,s.getTexture()->getSize().y*j);
                    target.draw(s,states);
                break;

                case 1:
                    s=_sprite[1];
                    s.setPosition(s.getTexture()->getSize().x*i,s.getTexture()->getSize().y*j);
                    target.draw(s,states);
                break;

                case 2:
                    s=_sprite[2];
                    s.setPosition(s.getTexture()->getSize().x*i,s.getTexture()->getSize().y*j);
                    target.draw(s,states);
                break;

                case 3:
                    s=_sprite[3];
                    s.setPosition(s.getTexture()->getSize().x*i,s.getTexture()->getSize().y*j);
                    target.draw(s,states);
                break;

                case 4:
                    s=_sprite[4];
                    s.setPosition(s.getTexture()->getSize().x*i,s.getTexture()->getSize().y*j);
                    target.draw(s,states);
                break;

            }
        }*/
    target.draw(_sprite[0],states);

}
void Game::onEvent(sf::Event & event){}
void Game::update(){}
Game::~Game(){}
