#ifndef GAME_H
#define GAME_H


#include "headers.hpp"


#include "Menu.hpp"
#include "Bouton.hpp"
#include "ScreenElement.hpp"
#include "fn_string.hpp"
#include "fn_time.hpp"
#include "fn_random.hpp"
#include "Evenement.hpp"
#include "AudioConfiguration.hpp"
#include <cassert>

using namespace std;
using namespace sf;



class Game : public ScreenElement
{
    private:
        vector<sf::Texture> _text;
        char *_state;
        int _map[50][50];
    protected:
        // sf::Drawable
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    public:

        Game();
        virtual ~Game();

        virtual void onEvent(sf::Event & event);
        virtual void update();

};

#endif // GAME_H
