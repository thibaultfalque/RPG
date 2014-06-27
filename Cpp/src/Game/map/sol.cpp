#include "sol.hpp"

Sol::Sol(){
   for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            _map[i][j]=rand_int(0,4);

    for(int i=0;i<5;i++){
        _text[i]=Ressources::getTexture("res/images/test/"+to_string(i)+".png");
    }
}


void Sol::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    sf::Sprite s;
    s.setOrigin(41,42);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++){
            s.setTexture(*(_text[_map[i][j]]));
            s.setPosition(i*41 - j*41,j*21 + i*21);
            target.draw(s,states);
        }
}
