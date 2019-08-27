#include "Meteor.hh"

Meteor::Meteor()
{
    double randY = rand() % 150 + (Constants::SCREEN_HEIGHT / 2);

    /** Player properties **/
    this->charType = CharacterType::MeteorType;
    this->life = 5;
    this->x = 0;
    this->y = randY;
    this->frameNumber = 0;

    /** Set the player sprite **/
    this->sprite.setTexture(ResourceHandler::GetInstance().textures.Get("meteor.png"));
    this->sprite.setTextureRect(sf::IntRect(0, 0, this->WIDTH, this->HEIGHT));
    this->sprite.setScale(0.8, 0.8);
}

Meteor::~Meteor()
{

}

void Meteor::Update(EventHandler *eventHandler)
{
    if (GetX() > Constants::SCREEN_WIDTH)
    {
        SetToBeRemoved(true);
    }

    SetX(GetX() + SPEED);

    this->SetSpritePosition();
}

void Meteor::Draw(sf::RenderWindow& win)
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

bool Meteor::HasCollide(Event<sf::FloatRect>* e)
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
