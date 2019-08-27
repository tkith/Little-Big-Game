#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Utility/EventHandler.hh"
#include "../Utility/Constants.hh"
#include "../Interface/ISerializable.hh"

using namespace std;

/*
 * Abstract class for every entities.
 */
class AbstractEntity : public ISerializable
{
    public:
		AbstractEntity();
		virtual ~AbstractEntity();
		// Draw the entity on the window
        virtual void Draw(sf::RenderWindow&) = 0;
		// Update the entity position/state
        virtual void Update(EventHandler*) = 0;
        virtual string Serialize() = 0;
		// Get the entity sprite
        virtual sf::Sprite GetSprite() { return sprite; };
		// Get sprite box
        virtual sf::FloatRect GetSpriteBox() { return sprite.getGlobalBounds(); };
        // Remove the entity
		virtual void SetToBeRemoved(bool b) { toBeRemoved = b; };
        virtual bool GetToBeRemoved() { return toBeRemoved; };

    protected:
        sf::Sprite sprite;
        bool toBeRemoved = false;
};

#endif // ABSTRACTENTITY_H
