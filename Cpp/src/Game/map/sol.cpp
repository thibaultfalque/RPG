#include "sol.hpp"

Sol::Sol(){

   for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            _map[i][j]=rand_int(0,4);

    for(int i=0;i<5;i++){
        _text[i]=Ressources::getTexture("res/images/test/"+to_string(i)+".png");
        _ratio[i] = Vector2f(float(SOL_WIDTH)/_text[i]->getSize().x,float(SOL_HEIGHT)/_text[i]->getSize().y);
    }

}


void Sol::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    sf::Sprite s;
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++){
            s.setTexture(*(_text[_map[i][j]]));
            s.setScale(_ratio[_map[i][j]]);
            s.setOrigin(SOL_WIDTH/2,SOL_HEIGHT);
            s.setPosition((i-j)*SOL_WIDTH/2,
                          (i+j)*SOL_HEIGHT/2);
            target.draw(s,states);
        }
}
