#ifndef STAGE_H
#define STAGE_H

#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "ResourceHandler.hh"

class Stage : public AbstractEntity
{
    public:
        Stage();
        virtual ~Stage();
        virtual double GetX() const;
        virtual void SetX(double);
        virtual double GetY() const;
        virtual void SetY(double);
        virtual void Draw(sf::RenderWindow&);
        virtual void Update(EventHandler*);
        virtual string Serialize() { return ""; };
        virtual void SetSpritePosition();
        void SetStage(int s) { stage = s;};
        int GetStage() { return stage; };
        sf::Text GetStageText() { return text; };

    protected:

    private:
        double x;
        double y;
        int stage;
        sf::Text text;
};

#endif // STAGE_H
