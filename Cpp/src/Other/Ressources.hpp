#ifndef RESSOURCES_H
#define RESSOURCES_H

#include "headers.hpp"

using namespace std;
using namespace sf;

class Ressources
{
    public:
        static sf::Font * getDefaultFont();
        static sf::Texture * getTexture(string _chemin);

    private:
        static sf::Font * default_font;
        static map<string,sf::Texture> _textures;
};

#endif // RESSOURCES_H
