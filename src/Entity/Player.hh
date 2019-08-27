#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Character.hh"
#include "Constants.hh"
#include "Projectile.hh"
#include "ResourceHandler.hh"

class Player : public Character
{
    public:
        Player();
        virtual ~Player();
        void Initialization();
        void Update(EventHandler*);
        void Draw(sf::RenderWindow&);
        bool HasCollide(Event<sf::FloatRect>* e) override;
        bool IsAlive() { return this->life == 0 ? false : true; };

    protected:

    private:
        list<sf::Sprite> livesSprite;

        static constexpr double SPEED = 4.0;
        static constexpr double WIDTH = 113;
        static constexpr double HEIGHT = 75;
};

#endif // PLAYER_H
