#include "MonsterFactory.hh"

MonsterFactory::MonsterFactory()
{

}

MonsterFactory::~MonsterFactory()
{

}

/*
 * Create a new ennemy
 */
Character* MonsterFactory::Create(const string& s)
{
    if (s.compare("SmallEnnemy") == 0)
    {
        return new SmallEnnemy();
    }
    else if (s.compare("NormalEnnemy") == 0)
    {
        return new NormalEnnemy();
    }
    else if (s.compare("StrongEnnemy") == 0)
    {
        return new StrongEnnemy();
    }

    return NULL;
}

/*
 * Create multiple ennemies of same kind
 */
list<AbstractEntity*> MonsterFactory::CreateMultiple(const string& s, int nb)
{
    list<AbstractEntity*> listMonsters;
    int nb_entity_line = 5;
    double x = (Constants::SCREEN_WIDTH / nb_entity_line) - 10;
    double x_base = x;
    double y = 60;

    for (int i = 0; i < nb; i++)
    {
        if (i > 0 && (i % nb_entity_line) == 0)
        {
            x = x_base;
            y += 60;
        }

        Character *c = this->Create(s);
        c->SetX(x);
        c->SetY(y);
        listMonsters.push_front(c);

        x += 124;
    }

    return listMonsters;
}

/*
 * Generate random ennemies
 */
list<AbstractEntity*> MonsterFactory::CreateMultipleRandom(int nb)
{
    list<AbstractEntity*> listMonsters;
    int nb_entity_line = 5;
    double x = (Constants::SCREEN_WIDTH / nb_entity_line) - 10;
    double x_base = x;
    double y = 60;

    for (int i = 0; i < nb; i++)
    {
        if (i > 0 && (i % nb_entity_line) == 0)
        {
            x = x_base;
            y += 60;
        }

        /** Get random monster type **/
        string monsterType;
        int randType = rand() % 3 + 1;
        switch (randType)
        {
            case 1:
                monsterType = "SmallEnnemy";
                break;
            case 2:
                monsterType = "NormalEnnemy";
                break;
            case 3:
                monsterType = "StrongEnnemy";
                break;
        }

        Character *c = this->Create(monsterType);
        c->SetX(x);
        c->SetY(y);
        listMonsters.push_front(c);

        x += 124;
    }

    return listMonsters;
}

Character* MonsterFactory::Unserialize(const string& s)
{
    string typeclass;
    int life;
    double x;
    double y;
    string t = s;
    istringstream iss(t);
    iss >> typeclass;
    iss >> life;
    iss >> x;
    iss >> y;
    Character* c = Create(typeclass);
    c->SetLife(life);
    c->SetX(x);
    c->SetY(y);
    return c;
}
