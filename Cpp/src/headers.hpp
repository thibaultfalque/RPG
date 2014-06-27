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


// Defines

//States
#define GAME 0

// Application :
#define FPS_MAX 60
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

// Sol :
#define SOL_WIDTH 80
#define SOL_HEIGHT 40

#endif // HEADERS_HPP
