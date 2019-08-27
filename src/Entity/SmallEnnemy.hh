#ifndef SMALLENNEMY_H
#define SMALLENNEMY_H

#include <SFML/Graphics.hpp>
#include "Ennemy.hh"
#include "ResourceHandler.hh"

class SmallEnnemy : public Ennemy
{
    public:
        SmallEnnemy();
        virtual ~SmallEnnemy();

    protected:

    private:
        int WIDTH = 82;
        int HEIGHT = 84;
};

#endif // SMALLENNEMY_H
