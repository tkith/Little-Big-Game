#include "Ennemy.hh"

Ennemy::Ennemy()
{
}

Ennemy::~Ennemy()
{
}

void Ennemy::Update(EventHandler* eventHandler)
{
    if (frameNumber >= FRAME_MAX)
    {
        frameNumber = 0;
        goToLeft = !goToLeft;
    }

    double newX = goToLeft ? -1.5f : 1.5f;

    frameNumber++;
    SetX(GetX() + newX);

    /** Move the Ennemy **/
    this->SetSpritePosition();
}

void Ennemy::Draw(sf::RenderWindow& win)
{
    /** Change color if hit **/
    if (this->secondsFlashing > 0)
    {
        this->sprite.setColor(sf::Color(255, 255, 255, 128));
        this->secondsFlashing--;
    }
    else
    {
        this->sprite.setColor(sf::Color(255, 255, 255, 255));
    }

    win.draw(this->sprite);
}

bool Ennemy::HasCollide(Event<sf::FloatRect>* e)
{
    bool hasCollide = false;
    sf::FloatRect pos = *e->GetInfo();

    if (this->GetSpriteBox().intersects(pos))
    {
        if (this->life > 0)
        {
            this->life--;
            this->secondsFlashing = 5;
        }

        if (this->life == 0)
        {
            this->SetToBeRemoved(true);
        }

        hasCollide = true;
    }

    return hasCollide;
}
