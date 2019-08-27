#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceManager.hh"

class ResourceHandler
{
    public:
        static ResourceHandler &GetInstance() {
            static ResourceHandler rh_instance;

            return rh_instance;
        };

        ResourceManager<sf::Texture> textures = ResourceManager<sf::Texture>("resource/textures");
        ResourceManager<sf::SoundBuffer> sounds = ResourceManager<sf::SoundBuffer>("resource/sounds");
        ResourceManager<sf::Font> fonts = ResourceManager<sf::Font>("resource/fonts");

    private:
        ResourceHandler() {};
        ResourceHandler(ResourceHandler const&) {};
        ResourceHandler& operator=(ResourceHandler const&);
};

#endif // RESOURCEHANDLER_H
