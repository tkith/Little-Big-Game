#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "ResourceHandler.hh"

class Score : public AbstractEntity
{
    public:
        Score();
        virtual ~Score();
        virtual double GetX() const;
        virtual void SetX(double);
        virtual double GetY() const;
        virtual void SetY(double);
        virtual void Draw(sf::RenderWindow&);
        virtual void Update(EventHandler*);
        virtual string Serialize() { return ""; };
        virtual void SetSpritePosition();
        void SetScore(int s) { score = s;};
        int GetScore() { return score; };
        sf::Text GetScoreText() { return text; };

    protected:

    private:
        double x;
        double y;
        int score;
        sf::Text text;
};

#endif // SCORE_H
