#ifndef SMALLENNEMYPROJECTILE_H
#define SMALLENNEMYPROJECTILE_H

#include "Projectile.hh"


class SmallEnnemyProjectile : public Projectile
{
    public:
        SmallEnnemyProjectile();
        virtual ~SmallEnnemyProjectile();
        void Update(EventHandler*);

    protected:

    private:
        static constexpr double HEIGHT = 37;
        static constexpr double WIDTH = 9;
};

#endif // SMALLENNEMYPROJECTILE_H
