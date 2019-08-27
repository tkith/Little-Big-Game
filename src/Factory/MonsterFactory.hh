#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H

#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "../Entity/AbstractEntity.hh"
#include "../Entity/Character.hh"
#include "Constants.hh"
#include "NormalEnnemy.hh"
#include "StrongEnnemy.hh"
#include "../Entity/SmallEnnemy.hh"

using namespace std;

class MonsterFactory
{
    public:
        MonsterFactory();
        virtual ~MonsterFactory();
        Character* Create(const string&);
        list<AbstractEntity*> CreateMultiple(const string&, int);
        list<AbstractEntity*> CreateMultipleRandom(int nb);
        Character* Unserialize(const string&);

    protected:

    private:
};

#endif // MONSTERFACTORY_H
