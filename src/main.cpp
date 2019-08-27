#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include "Utility/Constants.hh"
#include "Utility/EventHandler.hh"
#include "ResourceHandler.hh"
#include "Entity/Scene.hh"
#include "Utility/TimeManager.hh"

int main()
{
    /** Initialize random seed **/
    srand (time(NULL));

    /** Window settings **/
    sf::RenderWindow win(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT), "Space Invaders");
    win.setFramerateLimit(60);

    /** Create backgrounds **/
    // Normal
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(ResourceHandler::GetInstance().textures.Get("background.jpg"));
    // Gameover
    sf::Sprite backgroundGOSprite;
    backgroundGOSprite.setTexture(ResourceHandler::GetInstance().textures.Get("gameover.jpg"));

    /** Text replay **/
    sf::Text textGO;
    textGO.setFont(ResourceHandler::GetInstance().fonts.Get("another_flight.otf"));
    textGO.setString("Press SPACE to play again.");
    textGO.setFillColor(sf::Color::White);
    textGO.setPosition(Constants::SCREEN_WIDTH / 2.7, Constants::SCREEN_HEIGHT / 3);

    /** Set music **/
    sf::Music music;
    music.openFromFile("resource/sounds/ambiance.ogg");
    music.setLoop(true);
    music.setVolume(30);

    /** Set lose music **/
    sf::Music loseMusic;
    loseMusic.openFromFile("resource/sounds/lose.ogg");
    loseMusic.setLoop(true);
    loseMusic.setVolume(30);

    /** Create main entities **/
    EventHandler *eventhandler = new EventHandler();
    Scene *scene = new Scene();
    scene->Initialize();

    /** Game loop **/
    while (win.isOpen())
    {
        win.clear();

        if (!scene->IsGameOver())
        {
            if (music.getStatus() == sf::Sound::Status::Stopped)
            {
                loseMusic.stop();
                music.play();
            }
            win.draw(backgroundSprite);
            eventhandler->GetInput(win);
            scene->Update(win, eventhandler);
        }
        else
        {
            if (loseMusic.getStatus() == sf::Sound::Status::Stopped)
            {
                music.stop();
                loseMusic.play();
            }
            win.draw(backgroundGOSprite);
            win.draw(textGO);
            win.draw(scene->GetScore());
            win.draw(scene->GetStage());
            eventhandler->GetInput(win);
            if (eventhandler->GetButton().replay == true)
            {
                scene->Initialize();
            }
        }

        win.display();
    }

    return 0;
}
