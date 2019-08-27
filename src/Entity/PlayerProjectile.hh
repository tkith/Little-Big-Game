#ifndef PLAYERPROJECTILE_HH
#define PLAYERPROJECTILE_HH

#include <SFML/Graphics.hpp>
#include "Projectile.hh"
#include "ResourceHandler.hh"

class PlayerProjectile : public Projectile
{
    public:
        PlayerProjectile();
        virtual ~PlayerProjectile();
        void Update(EventHandler*);

    protected:

    private:
        static constexpr double HEIGHT = 37;
        static constexpr double WIDTH = 9;
};

#endif // PLAYERPROJECTILE_HH
