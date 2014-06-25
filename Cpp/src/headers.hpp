#ifndef HEADERS_HPP
#define HEADERS_HPP

// Bibliothèques standard C++
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <regex>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <vector>

#ifndef WIN32
    #include <sys/types.h>
#endif

// Bibliothèques SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
//Pour l'affichage 3D
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

//States
#define GAME 0

// Defines

// Application :
#define FPS_MAX 60
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540



#endif // HEADERS_HPP
