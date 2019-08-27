#ifndef ENNEMY_H
#define ENNEMY_H

#include <SFML/Graphics.hpp>
#include "Character.hh"
#include "ResourceHandler.hh"
#include "../Utility/TimeManager.hh"

typedef enum { SmallEnnemyType, NormalEnnemyType, StrongEnnemyType } EType;

class Ennemy : public Character
{
    public:
        Ennemy();
        virtual ~Ennemy();
        virtual void Update(EventHandler*);
        virtual void Draw(sf::RenderWindow&);
        EType GetEType() { return ennemyType; };
        bool HasCollide(Event<sf::FloatRect>* e) override;
        bool IsAlive() { return this->life == 0 ? false : true; };

    protected:
        bool goToLeft = false;
        int frameNumber = 0;
        static constexpr int FRAME_MAX = 30;
        EType ennemyType;
};

#endif // ENNEMY_H
