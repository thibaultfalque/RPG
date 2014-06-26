#ifndef _SOL_HPP_
#define _SOL_HPP_

#include "headers.hpp"
#include "fn_random.hpp"
#include "Ressources.hpp"

class Sol : public sf::Drawable{

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        Sol();

    private:

        char _map[50][50];
        sf::Texture* _text[5];
};


#endif // _SOL_HPP_
