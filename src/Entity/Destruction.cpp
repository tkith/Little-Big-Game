#include "Destruction.hh"

Destruction::Destruction()
{
    this->currentFrame = 0;
    this->sprite.setTexture(ResourceHandler::GetInstance().textures.Get("damage1.png"));

    /** Add frames **/
    for (int i = 1; i <= 3; ++i)
    {
        Frame* frame = new Frame;
        frame->texture = ResourceHandler::GetInstance().textures.Get("damage" + to_string(i) + ".png");
        frame->time = 5;

        listFrame.push_back(frame);
    }
}

Destruction::~Destruction()
{
}

void Destruction::Draw(sf::RenderWindow &win)
{
    win.draw(this->sprite);
}

void Destruction::Update(EventHandler *eventHandler)
{
    /** If end of animation, remove entity **/
    if (this->currentFrame >= (listFrame.size() - 1))
    {
        this->toBeRemoved = true;
    }
    else
    {
        if (listFrame.at(this->currentFrame)->time > 0)
        {
            listFrame.at(this->currentFrame)->time--;
        }
        else
        {
            this->currentFrame++;
        }
        this->sprite.setTexture(listFrame.at(this->currentFrame)->texture);
        this->sprite.setScale(0.6, 0.6);
    }

    this->SetSpritePosition();
}

double Destruction::GetX() const
{
    return this->x;
}

void Destruction::SetX(double x)
{
    this->x = x;
}

double Destruction::GetY() const
{
    return this->y;
}

void Destruction::SetY(double y)
{
    this->y = y;
}

void Destruction::SetSpritePosition()
{
    this->sprite.setPosition(GetX(), GetY());
}
