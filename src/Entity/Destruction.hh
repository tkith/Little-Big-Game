#ifndef DESTRUCTION_H
#define DESTRUCTION_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "ResourceHandler.hh"

struct Frame {
    sf::Texture texture;
    int time;
};

class Destruction : public AbstractEntity
{
    public:
        Destruction();
        virtual ~Destruction();
        virtual double GetX() const;
        virtual void SetX(double);
        virtual double GetY() const;
        virtual void SetY(double);
        virtual void Draw(sf::RenderWindow&);
        virtual void Update(EventHandler*);
        virtual void SetSpritePosition();
        virtual string Serialize() { return ""; };

    protected:

    private:
        double x;
        double y;

        vector<Frame*> listFrame;
        unsigned int currentFrame;
};

#endif // DESTRUCTION_H
