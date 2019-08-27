#ifndef NORMALENNEMY_H
#define NORMALENNEMY_H

#include <SFML/Graphics.hpp>
#include "Ennemy.hh"
#include "ResourceHandler.hh"

class NormalEnnemy : public Ennemy
{
    public:
        NormalEnnemy();
        virtual ~NormalEnnemy();

    protected:

    private:
        int WIDTH = 103;
        int HEIGHT = 84;
};

#endif // NORMALENNEMY_H
