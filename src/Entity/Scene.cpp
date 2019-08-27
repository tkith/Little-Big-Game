#include "Scene.hh"
#include "../Utility/TimeManager.hh"

Scene::Scene()
{

}

Scene::~Scene()
{

}

/** Initialize the player **/
void Scene::Initialize()
{
    /** Start the timer **/
    TimeManager::GetInstance().Start();

    /** Reset **/
    this->gameOver = false;
    this->listEntities.clear();

    /** Create score and stage **/
    score = new Score();
    this->AddEntity(score);
    stage = new Stage();
    this->AddEntity(stage);

    /** Create player **/
    Player *p = new Player();
    p->Initialization();
    this->AddEntity(p);
    this->SetPlayer(p);

    /** Create ennemies **/
    mf = new MonsterFactory();
    list<AbstractEntity*> listMonsters = mf->CreateMultiple("SmallEnnemy", 20);
    this->AddMultipleEntity(listMonsters);

    /** Set projectiles' sounds **/
    pSoundBuffer.loadFromFile("resource/sounds/ennemyprojectile.ogg");
    pSound.setBuffer(pSoundBuffer);
    pSound.setVolume(30);
    eSoundBuffer.loadFromFile("resource/sounds/ennemyprojectile.ogg");
    eSound.setBuffer(eSoundBuffer);
    eSound.setVolume(30);
}

/** Get all entities **/
list<AbstractEntity*> Scene::GetEntities() const
{
    return this->listEntities;
}

/** Add an entity **/
void Scene::AddEntity(AbstractEntity* ae)
{
    this->listEntities.push_front(ae);
}

/** Add many entities **/
void Scene::AddMultipleEntity(list<AbstractEntity*> listae)
{
    for (list<AbstractEntity*>::iterator it = listae.begin(); it != listae.end(); ++it)
    {
        this->AddEntity(*it);
    }
}

/** Remove an entity **/
void Scene::RemoveEntity(AbstractEntity* ae)
{
    this->listEntities.remove(ae);
}

/** Update all entities **/
void Scene::Update(sf::RenderWindow &win, EventHandler *eventHandler)
{
    if (player->IsAlive() && GetEnnemies().size() > 0)
    {
        /** If the player is alive and has pressed the shoot key **/
        if (eventHandler->GetButton().shoot == true)
        {
            PlayerShoot();
            TimeManager::GetInstance().Update();
        }

        /** Make ennemies shoot **/
        EnnemiesShoot();

        /** Add random meteor **/
        AddMeteor();

        /** Update all entities **/
        for (list<AbstractEntity*>::iterator it = this->listEntities.begin(); it != this->listEntities.end(); ++it)
        {
            if ((*it)->GetToBeRemoved())
            {
                /** Check if an ennemy died, add score **/
                if (Character* c = dynamic_cast<Character*>(*it))
                {
                    if (CharacterType::EnnemyType == c->GetCharType())
                    {
                        Ennemy* e = dynamic_cast<Ennemy*>(c);

                        /** Change score **/
                        int addScore;
                        int actualScore = score->GetScore();

                        switch (e->GetEType())
                        {
                            case EType::SmallEnnemyType:
                                addScore = 1;
                                break;
                            case EType::NormalEnnemyType:
                                addScore = 2;
                                break;
                            case EType::StrongEnnemyType:
                                addScore = 3;
                                break;
                        }
                        score->SetScore(actualScore + addScore);

                        /** Add destruction **/
                        Destruction *d = new Destruction();
                        d->SetX(c->GetX());
                        d->SetY(c->GetY());
                        d->SetSpritePosition();
                        AddEntity(d);
                    }
                }

                RemoveEntity((*it));
            }
            else
            {
                (*it)->Update(eventHandler);
            }
        }

        /** Draw all entities **/
        for (list<AbstractEntity*>::iterator it = this->listEntities.begin(); it != this->listEntities.end(); ++it)
        {
            (*it)->Draw(win);
        }
    }
    else
    {
        if (player->IsAlive())
        {
            stage->SetStage(stage->GetStage() + 1);
            list<AbstractEntity*> listMonsters = mf->CreateMultipleRandom(20);
            this->AddMultipleEntity(listMonsters);
        }
        else
        {
            /** Player is dead, game over **/
            this->gameOver = true;
        }
    }
}

/** Get all but ennemies **/
list<Character*> Scene::GetAllButEnnemies()
{
    list<Character*> listAllButEnnemies;

    for (list<AbstractEntity*>::iterator it = this->listEntities.begin(); it != this->listEntities.end(); ++it)
    {
        if (Character* c = dynamic_cast<Character*>(*it))
        {
            if (CharacterType::PlayerType == c->GetCharType())
            {
                listAllButEnnemies.push_front(c);
            }
        }
    }

    return listAllButEnnemies;
}

/** Get all ennemies **/
list<Character*> Scene::GetEnnemies()
{
    list<Character*> listEnnemies;

    for (list<AbstractEntity*>::iterator it = this->listEntities.begin(); it != this->listEntities.end(); ++it)
    {
        if (Character* c = dynamic_cast<Character*>(*it))
        {
            if (CharacterType::EnnemyType == c->GetCharType())
            {
                listEnnemies.push_front(c);
            }
        }
    }

    return listEnnemies;
}

/** Get meteors **/
list<Character*> Scene::GetMeteors()
{
    list<Character*> listMeteors;

    for (list<AbstractEntity*>::iterator it = this->listEntities.begin(); it != this->listEntities.end(); ++it)
    {
        if (Character* c = dynamic_cast<Character*>(*it))
        {
            if (CharacterType::MeteorType == c->GetCharType())
            {
                listMeteors.push_front(c);
            }
        }
    }

    return listMeteors;
}

/** Get player's projectiles **/
list<Projectile*> Scene::GetPlayerProjectiles()
{
    list<Projectile*> listProjectiles;

    for (list<AbstractEntity*>::iterator it = this->listEntities.begin(); it != this->listEntities.end(); ++it)
    {
        if (Projectile* p = dynamic_cast<Projectile*>(*it))
        {
            if (ProjectileType::PlayerProjectileType == p->GetProjectileType())
            {
                listProjectiles.push_front(p);
            }
        }
    }

    return listProjectiles;
}

/** Get ennemies' projectiles **/
list<Projectile*> Scene::GetEnnemiesProjectiles()
{
    list<Projectile*> listProjectiles;

    for (list<AbstractEntity*>::iterator it = this->listEntities.begin(); it != this->listEntities.end(); ++it)
    {
        if (Projectile* p = dynamic_cast<Projectile*>(*it))
        {
            if (ProjectileType::EnnemyProjectileType == p->GetProjectileType())
            {
                listProjectiles.push_front(p);
            }
        }
    }

    return listProjectiles;
}

/** Get last row ennemies **/
vector<Character*> Scene::GetLastRowEnnemies()
{
    map<double, list<Character*>> mapEnnemies;
    vector<Character*> listLastRowEnnemies;

    /** Get all ennemies and sort them in a map by their X position **/
    list<Character*> listEnnemies = GetEnnemies();
    for (list<Character*>::iterator it = listEnnemies.begin(); it != listEnnemies.end(); ++it)
    {
        mapEnnemies[(*it)->GetX()].push_back((*it));
    }

    /** Find the last row ennemies **/
    for (map<double, list<Character*>>::iterator it = mapEnnemies.begin(); it != mapEnnemies.end(); ++it)
    {
        Character* lastEnnemy = *(it->second).begin();

        for (list<Character*>::iterator it2 = (it->second).begin(); it2 != (it->second).end(); ++it2)
        {
            if ((*it2)->GetY() > lastEnnemy->GetY())
            {
                lastEnnemy = (*it2);
            }
        }

        listLastRowEnnemies.push_back(lastEnnemy);
    }

    return listLastRowEnnemies;
}

void Scene::PlayerShoot()
{
    double elapsedTime = TimeManager::GetInstance().GetElapsedTime() * 0.1;

    if (elapsedTime > 5.0)
    {
        double playerWidth = player->GetSpriteBox().width / 2.2;
        double playerHeight = player->GetSpriteBox().height / 2.5;

        PlayerProjectile *p = new PlayerProjectile();
        p->SetX(player->GetX() + playerWidth);
        p->SetY(player->GetY() - playerHeight);
        p->SetSpritePosition();

        /** Add ennemies as observers **/
        list<Character*> listEnnemies = GetEnnemies();
        for (list<Character*>::iterator it = listEnnemies.begin(); it != listEnnemies.end(); ++it)
        {
            p->AddObserver((*it));
        }

        /** Add ennemies's projectiles as observers **/
        list<Projectile*> listProjectiles = GetEnnemiesProjectiles();
        for (list<Projectile*>::iterator it = listProjectiles.begin(); it != listProjectiles.end(); ++it)
        {
            p->AddObserver((*it));
        }

        /** Add meteors as observers **/
        list<Character*> listMeteors = GetMeteors();
        for (list<Character*>::iterator it = listMeteors.begin(); it != listMeteors.end(); ++it)
        {
            p->AddObserver((*it));
        }

        AddEntity(p);

        PlayShootSound(ProjectileType::PlayerProjectileType);
    }
}

void Scene::EnnemiesShoot()
{
    int randCanShoot = rand() % 80 + 1;

    if (randCanShoot == 1)
    {
        vector<Character*> lastRowEnnemies = GetLastRowEnnemies();

        /** Choose randomly which ennemy will shoot **/
        int randNumEnnemy = rand() % lastRowEnnemies.size();

        /** Create the projectile **/
        double ennemyWidth = lastRowEnnemies.at(randNumEnnemy)->GetSpriteBox().width / 2.2;
        double ennemyHeight = lastRowEnnemies.at(randNumEnnemy)->GetSpriteBox().height / 2.5;

        SmallEnnemyProjectile *p = new SmallEnnemyProjectile();
        p->SetX(lastRowEnnemies.at(randNumEnnemy)->GetX() + ennemyWidth);
        p->SetY(lastRowEnnemies.at(randNumEnnemy)->GetY() - ennemyHeight);
        p->SetSpritePosition();

        /** Add observers **/
        p->AddObserver(player);

        /** Add player's projectiles as observers **/
        list<Projectile*> listProjectiles = GetPlayerProjectiles();
        for (list<Projectile*>::iterator it = listProjectiles.begin(); it != listProjectiles.end(); ++it)
        {
            p->AddObserver((*it));
        }

        /** Add meteors as observers **/
        list<Character*> listMeteors = GetMeteors();
        for (list<Character*>::iterator it = listMeteors.begin(); it != listMeteors.end(); ++it)
        {
            p->AddObserver((*it));
        }

        AddEntity(p);

        PlayShootSound(ProjectileType::EnnemyProjectileType);
    }
}

/** Play a sound **/
void Scene::PlayShootSound(ProjectileType type)
{
    switch (type)
    {
        case ProjectileType::EnnemyProjectileType:
            /** Set projectile sound **/
            eSound.play();
            break;
        case ProjectileType::PlayerProjectileType:
            /** Set projectile sound **/
            pSound.play();
            break;
    }
}

void Scene::AddMeteor()
{
    int randMeteor = rand() % 200 + 1;

    if (randMeteor == 1)
    {
        Meteor *m = new Meteor();
        AddEntity(m);
    }
}
