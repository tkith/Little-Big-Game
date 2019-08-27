#ifndef STRONGENNEMY_H
#define STRONGENNEMY_H

#include <SFML/Graphics.hpp>
#include "Ennemy.hh"
#include "ResourceHandler.hh"

class StrongEnnemy : public Ennemy
{
    public:
        StrongEnnemy();
        virtual ~StrongEnnemy();

    protected:

    private:
        int WIDTH = 103;
        int HEIGHT = 84;
};

#endif // STRONGENNEMY_H
