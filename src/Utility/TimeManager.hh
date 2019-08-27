#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

class TimeManager
{
    private:
        TimeManager() {};
        TimeManager(TimeManager const&) {};
        TimeManager& operator=(TimeManager const&);

        chrono::milliseconds start_time;
        chrono::milliseconds update_time;
        chrono::milliseconds last_update_time;

    public:
        virtual ~TimeManager() {};
        static TimeManager &GetInstance() {
            static TimeManager tm_instance;

            return tm_instance;
        };
        void Start();
        void Update();
        unsigned int GetElapsedTime() const;
        unsigned int GetStartedTime() const;
        chrono::milliseconds GetUpdateTime() { return update_time; };
};

#endif // TIMEMANAGER_H
