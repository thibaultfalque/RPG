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
#include "sol.hpp"
#include <cassert>

using namespace std;
using namespace sf;



class Game : public ScreenElement
{
    private:
        char *_state;

        Sol _sol;

        sf::View _viewMain;
        sf::View _viewGame;
        sf::Sprite _cursor;

        Evenement & _event;
    protected:
        // sf::Drawable
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    public:

        Game(Evenement & e);
        virtual ~Game();

        virtual void onEvent(sf::Event & event);
        virtual void update(sf::Time elapsedTime);

};

#endif // GAME_H
