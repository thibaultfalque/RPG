#ifndef FN_STRING_HPP
#define FN_STRING_HPP


#include "headers.hpp"

using namespace std;


float string_to_float( const string & Str);

int string_to_int( const string & Str);

#ifdef _WIN32
string to_string( int Value );
#endif

string to_string( int Value, unsigned int nb_car );

string to_string( int Value, string separateur_millier );

string to_string( long long Value );

string to_string( double Value );

string to_string( bool Value );

int nombre_car_mot(string mot, char l);

bool sont_anagramme(string mot1, string mot2);

vector<string> explode(const string& str, const char& ch);

string wordwrap(string str, unsigned int width);

vector<sf::String> explode(const sf::String& str, wchar_t ch);

sf::String wordwrap(sf::String str, unsigned int width);

string implode(vector<string> & tabstr, string ch);

sf::String implode(vector<sf::String> & tabstr, sf::String ch);

int nombre_mot(string & chaine);

bool sont_palindrome(string mot);

// compte le nombre d'occurence se pattern dans chaine
int substr_count(string chaine, string pattern);

map<string, int> iterration_mots(string texte);


string str_replace_car(char match, char replaced, string str);


#endif // FN_STRING_HPP
