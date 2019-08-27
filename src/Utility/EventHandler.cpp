#include "EventHandler.hh"

EventHandler::EventHandler()
{
    button.left = button.right = button.shoot = button.replay = false;
}

EventHandler::~EventHandler()
{

}

EventHandler::Button EventHandler::GetButton()
{
    return button;
}

void EventHandler::SetButton(int b, bool state)
{
    switch (b)
    {
        case left:
            button.left = state;
            break;
        case right:
            button.right = state;
            break;
        case shoot:
            button.shoot = state;
            break;
        case replay:
            button.replay = state;
            break;
    }
}

void EventHandler::GetInput(sf::RenderWindow &win)
{
    while (win.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                win.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Left:
                        button.left = true;
                        break;
                    case sf::Keyboard::Right:
                        button.right = true;
                        break;
                    case sf::Keyboard::X:
                        button.shoot = true;
                        break;
                    case sf::Keyboard::Space:
                        button.replay = true;
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Left:
                        button.left = false;
                        break;
                    case sf::Keyboard::Right:
                        button.right = false;
                        break;
                    case sf::Keyboard::X:
                        button.shoot = false;
                        break;
                    case sf::Keyboard::Space:
                        button.replay = false;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}
