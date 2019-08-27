#include "Character.hh"

Character::Character()
{

}

Character::~Character()
{

}

void Character::Draw(sf::RenderWindow &win)
{
    win.draw(sprite);
}

void Character::Update(EventHandler *eventHandler)
{

}

double Character::GetX() const
{
    return this->x;
}

void Character::SetX(double x)
{
    this->x = x;
}

double Character::GetY() const
{
    return this->y;
}

void Character::SetY(double y)
{
    this->y = y;
}

int Character::GetLife() const
{
    return this->life;
}

void Character::SetLife(int life)
{
    this->life = life;
}

void Character::SetSpritePosition()
{
    this->sprite.setPosition(GetX(), GetY());
}

Event<sf::FloatRect>* Character::GetEvent()
{
    return new Event<sf::FloatRect>(new sf::FloatRect(this->GetSpriteBox()));
}

/*
 * Check if the character has collide with other entities by checking their position.
 * Returns a boolean.
 */
bool Character::HasCollide(Event<sf::FloatRect>* e)
{
    bool hasCollide = false;
    sf::FloatRect pos = *e->GetInfo();

    if (this->GetSpriteBox().intersects(pos))
    {
        this->SetToBeRemoved(true);
        hasCollide = true;
    }

    return hasCollide;
}
