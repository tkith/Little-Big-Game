#include "SmallEnnemy.hh"

SmallEnnemy::SmallEnnemy()
{
    /** SmallEnnemy properties **/
    this->charType = CharacterType::EnnemyType;
    this->ennemyType = EType::SmallEnnemyType;
    this->life = 1;

    /** Set SmallEnnemy sprite **/
    this->sprite.setTexture(ResourceHandler::GetInstance().textures.Get("smallennemy.png"));
    this->sprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
    this->sprite.setScale(0.5, 0.5);
}

SmallEnnemy::~SmallEnnemy()
{

}
