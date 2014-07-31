#include "sol.hpp"

Sol::Sol(){

    int width = 100;
    int height = 100;

    m_tileset = Ressources::getTexture("res/images/test2/3.png");

    Vector2i ts = Vector2i(m_tileset->getSize().x/3.0,m_tileset->getSize().y/3.0);


    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++){
        m_vertices[i][j].setPrimitiveType(sf::Quads);
        m_vertices[i][j].resize(10 * 10 * 4);
    }

    for (int i = 0; i < width; ++i)
            for (int j = 0; j < height; ++j)
            {

                // on en déduit sa position dans la texture du tileset
                int tu = rand_int(0,2)*ts.x;
                int tv = rand_int(0,2)*ts.y;

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[i/10][j/10][(i%10 + j%10 * 10) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f((i-j)*SOL_WIDTH/2,
                                                (i+j)*SOL_HEIGHT/2);

                quad[1].position = sf::Vector2f((i-j+2)*SOL_WIDTH/2,
                                                (i+j)*SOL_HEIGHT/2);

                quad[2].position = sf::Vector2f((i-j+2)*SOL_WIDTH/2,
                                                (i+j+2)*SOL_HEIGHT/2);

                quad[3].position = sf::Vector2f((i-j)*SOL_WIDTH/2,
                                                (i+j+2)*SOL_HEIGHT/2);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu, tv);
                quad[1].texCoords = sf::Vector2f(tu+ts.x, tv);
                quad[2].texCoords = sf::Vector2f(tu+ts.x, tv+ts.y);
                quad[3].texCoords = sf::Vector2f(tu, tv+ts.y);
            }


}

void Sol::graphicUpdate(sf::View view){
    AABB rView;
    rView.x = view.getCenter().x - view.getSize().x/2;
    rView.y = view.getCenter().y - view.getSize().y/2;
    rView.x2 = rView.x + view.getSize().x;
    rView.y2 = rView.y + view.getSize().y;
    AABB rText;
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++){
        rText.x = i*5*SOL_WIDTH - j*5*SOL_WIDTH - 4.5*SOL_WIDTH;
        rText.y = i*5*SOL_HEIGHT + j*5*SOL_HEIGHT;
        rText.x2 = rText.x + 10*SOL_WIDTH;
        rText.y2 = rText.y + 10*SOL_HEIGHT;

        _toDraw[i][j]=AABBinAABB(rView,rText);
    }

}


void Sol::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = m_tileset;
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
        if(_toDraw[i][j])
        target.draw(m_vertices[i][j], states);

}
