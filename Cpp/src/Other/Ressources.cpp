#include "Ressources.hpp"

sf::Font * Ressources::default_font = nullptr;
map<string,sf::Texture> Ressources::_textures;


sf::Font * Ressources::getDefaultFont()
{
    if (default_font == nullptr)
    {
        default_font = new sf::Font();
        if (!default_font->loadFromFile("res/LiberationMono-Regular.ttf"))
            cerr << (L"Erreur lors du chargement du fichier de police de caractère\nVérifiez la présence d'un fichier nommé \"res/LiberationMono-Regular.ttf\"");
    }
    return default_font;
}

sf::Texture * Ressources::getTexture(string _chemin){

    if(_textures.find(_chemin) == _textures.end()){

        _textures[_chemin]=sf::Texture();

        if(_textures[_chemin].loadFromFile(_chemin))
            cout << "Chargement de l'image : \"" << _chemin << "\""<<endl;
        else
            cout << "Erreur lors du chargement de l'image : \"" << _chemin << "\""<<endl;

    }

    return &_textures[_chemin];
}
