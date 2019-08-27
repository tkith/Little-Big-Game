#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include "AbstractEntity.hh"
#include "../Interface/IObservable.hh"
#include "../Interface/IObserver.hh"
#include "Event.hh"
#include "../Utility/EventHandler.hh"

typedef enum { PlayerType, EnnemyType, MeteorType } CharacterType;

class Character : public AbstractEntity, public IObservable<sf::FloatRect>, public IObserver<sf::FloatRect>
{
    public:
        Character();
        virtual ~Character();
        virtual double GetX() const;
        virtual void SetX(double);
        virtual double GetY() const;
        virtual void SetY(double);
        virtual int GetLife() const;
        virtual void SetLife(int);
        virtual void Draw(sf::RenderWindow&);
        virtual void Update(EventHandler*);
        virtual string Serialize() { return ""; };
        virtual void SetSpritePosition();
        CharacterType GetCharType() { return charType; };
        void AddObserver(IObserver<sf::FloatRect>* obs)
        {
            IObservable<sf::FloatRect>::AddObserver(obs);
        }
        void RemoveObserver(IObserver<sf::FloatRect>* obs)
        {
            IObservable<sf::FloatRect>::RemoveObserver(obs);
        }
        bool HasCollide(Event<sf::FloatRect>* e);

    protected:
        double x;
        double y;
        int life;
        CharacterType charType;
        int secondsFlashing = 0;

        Event<sf::FloatRect>* GetEvent();
};

#endif // CHARACTER_H
