#include "Score.hh"

Score::Score()
{
    score = 0;
    text.setFont(ResourceHandler::GetInstance().fonts.Get("another_flight.otf"));
    text.setString("SCORE: " + to_string(score));
    text.setFillColor(sf::Color::White);
    text.setPosition(5, 5);
}

Score::~Score()
{
}

void Score::Draw(sf::RenderWindow &win)
{
    win.draw(text);
}

void Score::Update(EventHandler *eventHandler)
{
    text.setString("SCORE: " + to_string(score));
}

double Score::GetX() const
{
    return this->x;
}

void Score::SetX(double x)
{
    this->x = x;
}

double Score::GetY() const
{
    return this->y;
}

void Score::SetY(double y)
{
    this->y = y;
}

void Score::SetSpritePosition()
{
    this->sprite.setPosition(GetX(), GetY());
}
