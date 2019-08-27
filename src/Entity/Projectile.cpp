#include "Projectile.hh"

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

void Projectile::Update(EventHandler* eventHandler)
{
}

void Projectile::Draw(sf::RenderWindow &win)
{
    win.draw(sprite);
}

double Projectile::GetX() const
{
    return this->x;
}

void Projectile::SetX(double x)
{
    this->x = x;
}

double Projectile::GetY() const
{
    return this->y;
}

void Projectile::SetY(double y)
{
    this->y = y;
}

void Projectile::SetSpritePosition()
{
    this->sprite.setPosition(GetX(), GetY());
}

Event<sf::FloatRect>* Projectile::GetEvent()
{
    return new Event<sf::FloatRect>(new sf::FloatRect(this->GetSpriteBox()));
}

bool Projectile::HasCollide(Event<sf::FloatRect>* e)
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
