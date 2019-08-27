#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <map>
#include <vector>
#include <stdlib.h>
#include <SFML/Audio.hpp>
#include "AbstractEntity.hh"
#include "Destruction.hh"
#include "../Utility/EventHandler.hh"
#include "../Interface/IObservable.hh"
#include "Meteor.hh"
#include "../Factory/MonsterFactory.hh"
#include "Player.hh"
#include "PlayerProjectile.hh"
#include "Score.hh"
#include "SmallEnnemyProjectile.hh"
#include "Stage.hh"

using namespace std;

class Scene
{
    public:
        Scene();
        virtual ~Scene();
        void Initialize();
        list<AbstractEntity*> GetEntities() const;
        void AddEntity(AbstractEntity*);
        void AddMultipleEntity(list<AbstractEntity*>);
        void RemoveEntity(AbstractEntity*);
        void Update(sf::RenderWindow&, EventHandler*);
        void SetPlayer(Player *p) { player = p; };
        bool IsGameOver() { return gameOver; };
        sf::Text GetScore() { return score->GetScoreText(); };
        sf::Text GetStage() { return stage->GetStageText(); };

    protected:

    private:
        MonsterFactory *mf;
        Player *player;
        list<AbstractEntity*> listEntities;
        bool gameOver;
        sf::SoundBuffer pSoundBuffer;
        sf::Sound pSound;
        sf::SoundBuffer eSoundBuffer;
        sf::Sound eSound;
        Score *score;
        Stage *stage;

        list<Character*> GetAllButEnnemies();
        list<Character*> GetEnnemies();
        list<Character*> GetMeteors();
        list<Projectile*> GetPlayerProjectiles();
        list<Projectile*> GetEnnemiesProjectiles();
        vector<Character*> GetLastRowEnnemies();
        void PlayerShoot();
        void EnnemiesShoot();
        void PlayShootSound(ProjectileType);
        void AddMeteor();
};

#endif // SCENE_H
