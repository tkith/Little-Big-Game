#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Graphics.hpp>

class EventHandler
{
    struct Button { bool left, right, shoot, replay; };

    public:
        EventHandler();
        virtual ~EventHandler();

        EventHandler::Button GetButton();
        void SetButton(int, bool);

        void GetInput(sf::RenderWindow&);

    protected:

    private:
        sf::Event event;
        Button button;
        enum { left, right, shoot, replay };
};

#endif // EVENTHANDLER_H
