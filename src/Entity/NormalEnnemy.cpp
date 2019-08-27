#include "NormalEnnemy.hh"

NormalEnnemy::NormalEnnemy()
{
    /** NormalEnnemy properties **/
    this->charType = CharacterType::EnnemyType;
    this->ennemyType = EType::NormalEnnemyType;
    this->life = 2;

    /** Set NormalEnnemy sprite **/
    this->sprite.setTexture(ResourceHandler::GetInstance().textures.Get("normalennemy.png"));
    this->sprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
    this->sprite.setScale(0.5, 0.5);
}

NormalEnnemy::~NormalEnnemy()
{
}
