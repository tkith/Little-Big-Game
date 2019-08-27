#ifndef METEOR_H
#define METEOR_H

#include "Character.hh"
#include "Constants.hh"
#include "ResourceHandler.hh"

class Meteor : public Character
{
    public:
        Meteor();
        virtual ~Meteor();
        void Initialization();
        void Update(EventHandler*);
        void Draw(sf::RenderWindow&);
        bool HasCollide(Event<sf::FloatRect>* e) override;
        bool IsAlive() { return this->life == 0 ? false : true; };

    private:
        static constexpr double SPEED = 1.5;
        static constexpr double WIDTH = 120;
        static constexpr double HEIGHT = 98;
        int frameNumber;
        static constexpr int FRAME_MAX = 100;
};

#endif // METEOR_H
