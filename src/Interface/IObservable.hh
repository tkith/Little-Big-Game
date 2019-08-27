#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

#include <list>
#include "IObserver.hh"
#include "Event.hh"

using namespace std;

template<typename Object>
class IObservable
{
    public:
        void AddObserver(IObserver<Object>* obs)
        {
            listObserver.push_back(obs);
        };
        void RemoveObserver(IObserver<Object>* obs)
        {
            ItListObserver beginList = listObserver.begin();
            ItListObserver endList = listObserver.end();
            ItListObserver it = find(beginList, endList, obs);
            if (it != endList)
            {
                listObserver.erase(it);
            }
        };

    protected:
        virtual Event<Object>* GetEvent() = 0;

		/*
		 * Check if any observers has collide with the observable
		 */
        bool Notify()
        {
            bool hasCollide = false;
            for(ItListObserver it = listObserver.begin(); it != listObserver.end(); ++it)
            {
                if ((*it)->HasCollide(this->GetEvent()))
                {
                    hasCollide = true;
                }
            }

            return hasCollide;
        };

    private:
        typedef IObserver<Object>* Observer;
        typedef list<Observer> ListObserver;
        typedef typename ListObserver::iterator ItListObserver;
        ListObserver listObserver;
};

#endif // IOBSERVABLE_H
