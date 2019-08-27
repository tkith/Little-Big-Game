#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "ResourceHandler.hh"
#include "../Interface/IObservable.hh"
#include "../Interface/IObserver.hh"
#include "Event.hh"
#include "../Utility/EventHandler.hh"

typedef enum { PlayerProjectileType, EnnemyProjectileType } ProjectileType;

class Projectile : public AbstractEntity, public IObservable<sf::FloatRect>, public IObserver<sf::FloatRect>
{
    public:
        Projectile();
        virtual ~Projectile();
        virtual double GetX() const;
        virtual void SetX(double);
        virtual double GetY() const;
        virtual void SetY(double);
        virtual void Update(EventHandler*);
        virtual void Draw(sf::RenderWindow&);
        virtual void SetSpritePosition();
        virtual string Serialize() { return ""; };
        ProjectileType GetProjectileType() { return projectileType; };
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
        int frameNumber;
        int FRAME_MAX = 30;
        ProjectileType projectileType;

        Event<sf::FloatRect>* GetEvent();
};

#endif // PROJECTILE_H
