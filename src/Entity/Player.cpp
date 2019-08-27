#include "Player.hh"

Player::Player()
{
    /** Player properties **/
    this->charType = CharacterType::PlayerType;

    /** Set the player sprite **/
    this->sprite.setTexture(ResourceHandler::GetInstance().textures.Get("player.png"));
    this->sprite.setTextureRect(sf::IntRect(0, 0, this->WIDTH, this->HEIGHT));
    this->sprite.setScale(0.8, 0.8);
}

Player::~Player()
{

}

void Player::Initialization()
{
    this->SetLife(3);

    /** Set the starting position **/
    double startingX;
    startingX = (Constants::SCREEN_WIDTH / 2) - (WIDTH / 2);
    this->SetX(startingX);
    this->SetY(Constants::SCREEN_HEIGHT - 100);

    /** Set lives sprite **/
    for (int i = 0; i < this->life; i++)
    {
        sf::Sprite lifeSprite;
        lifeSprite.setTexture(ResourceHandler::GetInstance().textures.Get("playerlife.png"));
        lifeSprite.setTextureRect(sf::IntRect(0, 0, 37, 26));
        lifeSprite.setPosition(5 + (i * 40), 45);
        this->livesSprite.push_back(lifeSprite);
    }
}

void Player::Update(EventHandler *eventHandler)
{
    /** Update position when a key is pressed **/
    if (eventHandler->GetButton().right == true)
    {
        double newX = this->GetX() + SPEED;
        this->SetX(newX);
    }
    else if (eventHandler->GetButton().left == true)
    {
        double newX = this->GetX() - SPEED;
        this->SetX(newX);
    }

    /** Reset position in case the player is outside the screen **/
    if (this->GetX() < 2)
    {
        this->SetX(2);
    }
    else if (this->GetX() > (Constants::SCREEN_WIDTH - 90))
    {
        this->SetX(Constants::SCREEN_WIDTH - 90);
    }

    this->SetSpritePosition();
}

void Player::Draw(sf::RenderWindow& win)
{
    /** Draw lives **/
    for (list<sf::Sprite>::iterator it = this->livesSprite.begin(); it != this->livesSprite.end(); ++it)
    {
        win.draw(*it);
    }

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

bool Player::HasCollide(Event<sf::FloatRect>* e)
{
    bool hasCollide = false;
    sf::FloatRect pos = *e->GetInfo();

	/** Compare sprite position to other entities on the window **/
    if (this->GetSpriteBox().intersects(pos))
    {
        if (this->life > 0)
        {
            this->life--;
            this->livesSprite.pop_back();
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
