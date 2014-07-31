#ifndef _SOL_HPP_
#define _SOL_HPP_

#include "headers.hpp"
#include "fn_random.hpp"
#include "Ressources.hpp"
#include "fn_collision.hpp"

class Sol : public sf::Drawable, public sf::Transformable{

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        Sol();
        void graphicUpdate(sf::View view);

    private:
    bool _toDraw[10][10];
    sf::VertexArray m_vertices[10][10];
    sf::Texture * m_tileset;
};
#endif // _SOL_HPP_
