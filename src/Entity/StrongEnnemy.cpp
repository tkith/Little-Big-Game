#include "StrongEnnemy.hh"

StrongEnnemy::StrongEnnemy()
{
    /** StrongEnnemy properties **/
    this->charType = CharacterType::EnnemyType;
    this->ennemyType = EType::StrongEnnemyType;
    this->life = 3;

    /** Set StrongEnnemy sprite **/
    this->sprite.setTexture(ResourceHandler::GetInstance().textures.Get("strongennemy.png"));
    this->sprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
    this->sprite.setScale(0.5, 0.5);
}

StrongEnnemy::~StrongEnnemy()
{
}
