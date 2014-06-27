#include "sol.hpp"

Sol::Sol(){
   /*for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            _map[i][j]=rand_int(0,4);

    for(int i=0;i<5;i++){
        _text[i]=Ressources::getTexture("res/images/test/"+to_string(i)+".png");
    }*/

    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            _map[i][j]=rand_int(0,10);

    for(int i=0;i<2;i++){
        _text[i]=Ressources::getTexture("res/images/test2/"+to_string(i)+".png");
    }
    int t=3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==0){
                _text[t+j]=new sf::Texture();
                if(!_text[t+j]->loadFromFile("res/images/test2/3.png",sf::IntRect(j*128,i*68,128,68)))
                    exit(1);
                else
                    cout<<"ok"<<endl;
                if(j==2)
                    t=t+j;
            }
            else if(i==1){
                _text[t+j+i]=new sf::Texture();
                if(!_text[t+i+j]->loadFromFile("res/images/test2/3.png",sf::IntRect(j*128,i*68,128,68)))
                    exit(1);
                else
                    cout<<"ok"<<endl;
                if(j==2)
                    t=t+j+i;
            }
            else{
                if(j==0){
                  _text[t+1]=new sf::Texture();
                  if(!_text[t+1]->loadFromFile("res/images/test2/3.png",sf::IntRect(j*128,i*68,128,68)))
                    exit(1);
                }
                if(j==1){
                  _text[t+2]=new sf::Texture();
                  if(!_text[t+2]->loadFromFile("res/images/test2/3.png",sf::IntRect(j*128,i*68,128,68)))
                    exit(1);
                }
                if(j==2){
                  _text[t+3]=new sf::Texture();
                  if(!_text[t+3]->loadFromFile("res/images/test2/3.png",sf::IntRect(j*128,i*68,128,68)))
                    exit(1);
                }
            }
            cout<<t<<endl;

        }

    }
    cout<<"ok"<<endl;
}


void Sol::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    sf::Sprite s;
    s.setOrigin(41,42);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++){
            s.setTexture(*(_text[_map[i][j]]));
            //s.setPosition(i*41 - j*41,j*21 + i*21);
            if(_map[i][j]==0)
                s.setPosition(i*64 - j*64,j*53 + i*53);
            else if(_map[i][j]==1)
                s.setPosition(i*64 - j*64,j*79 + i*79);
            else
                s.setPosition(i*64 - j*64,j*34 + i*34);

            target.draw(s,states);
        }
}
