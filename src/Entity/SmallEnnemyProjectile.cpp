#include "SmallEnnemyProjectile.hh"

SmallEnnemyProjectile::SmallEnnemyProjectile()
{
    /** Projectile properties **/
    this->projectileType = ProjectileType::EnnemyProjectileType;
    this->frameNumber = 1;

    /** Set projectile sprite **/
    this->sprite.setTexture(ResourceHandler::GetInstance().textures.Get("smallennemylaser.png"));
    this->sprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
    this->sprite.setScale(0.8, 0.8);
}

SmallEnnemyProjectile::~SmallEnnemyProjectile()
{
}

void SmallEnnemyProjectile::Update(EventHandler* eventHandler)
{
    if (frameNumber > FRAME_MAX)
    {
        toBeRemoved = true;
    }
    else
    {
        double newY = 20.0f;
        frameNumber++;
        SetY(GetY() + newY);
        this->sprite.setPosition(this->GetX(), this->GetY());
        if (this->Notify())
        {
            toBeRemoved = true;
        }
    }
}
