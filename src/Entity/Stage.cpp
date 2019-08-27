#include "Stage.hh"

Stage::Stage()
{
    stage = 1;
    text.setFont(ResourceHandler::GetInstance().fonts.Get("another_flight.otf"));
    text.setString("STAGE " + to_string(stage));
    text.setFillColor(sf::Color::White);
    text.setPosition(800, 5);
}

Stage::~Stage()
{
}

void Stage::Draw(sf::RenderWindow &win)
{
    win.draw(text);
}

void Stage::Update(EventHandler *eventHandler)
{
    text.setString("STAGE " + to_string(stage));
}

double Stage::GetX() const
{
    return this->x;
}

void Stage::SetX(double x)
{
    this->x = x;
}

double Stage::GetY() const
{
    return this->y;
}

void Stage::SetY(double y)
{
    this->y = y;
}

void Stage::SetSpritePosition()
{
    this->sprite.setPosition(GetX(), GetY());
}
