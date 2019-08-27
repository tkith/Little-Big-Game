#include "PlayerProjectile.hh"

PlayerProjectile::PlayerProjectile()
{
    /** Projectile properties **/
    this->projectileType = ProjectileType::PlayerProjectileType;
    this->frameNumber = 1;

    /** Set projectile sprite **/
    this->sprite.setTexture(ResourceHandler::GetInstance().textures.Get("playerlaser.png"));
    this->sprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
    this->sprite.setScale(0.8, 0.8);
}

PlayerProjectile::~PlayerProjectile()
{

}

void PlayerProjectile::Update(EventHandler* eventHandler)
{
    if (frameNumber > FRAME_MAX)
    {
        toBeRemoved = true;
    }
    else
    {
        double newY = -20.0f;
        frameNumber++;
        SetY(GetY() + newY);
        this->sprite.setPosition(this->GetX(), this->GetY());
        if (this->Notify())
        {
            toBeRemoved = true;
        }
    }
}
