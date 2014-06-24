#ifndef AUDIOCONFIGURATION_H
#define AUDIOCONFIGURATION_H

#include "headers.hpp"
#include "fn_file.hpp"
#include "fn_random.hpp"
#include "fn_string.hpp"ŝ

using namespace std;
using namespace sf;

class AudioConfiguration
{
    public:

        AudioConfiguration();
        virtual ~AudioConfiguration();

        void update();
        void setPlay(bool _state);
        bool getPlay();
        void setVolume(float volume);
        float getVolume();
        void changeMusic(int i);
        vector<string> getMusicList();
        int getMusicPlayingId();

        float getAudioLevel();

    protected:
        void loadFromFolder(std::string folder);
        void clearMusics();
        void addMusic(std::string file);
        bool loadConfigFromFile(std::string file);
        bool saveConfigurationFile();
        void initDefault();

        float _pGetAudioLevel();

    private:
        std::vector<sf::Music*> _musics;
        sf::SoundBuffer _buff_actual_music;
        vector<string> musicNames;
        bool _play;
        float _volume;
        int musicPlayed;
        string _folder;

        float _level;
};



#endif // AUDIOCONFIGURATION_H
