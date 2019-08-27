#include "TimeManager.hh"

void TimeManager::Start()
{
    this->start_time = duration_cast<std::chrono::milliseconds>(high_resolution_clock::now().time_since_epoch());
    this->update_time = this->start_time;
    this->last_update_time = this->start_time;
}

void TimeManager::Update()
{
    this->last_update_time = this->update_time;
    this->update_time = duration_cast<std::chrono::milliseconds>(high_resolution_clock::now().time_since_epoch());
}

unsigned int TimeManager::GetElapsedTime() const
{
    auto elapsed_time = this->update_time - this->last_update_time;

    if (elapsed_time.count() > 0) {
        return elapsed_time.count();
    }

    return 0;
}

unsigned int TimeManager::GetStartedTime() const
{
    auto started_time = this->update_time - this->start_time;
    return started_time.count();
}
