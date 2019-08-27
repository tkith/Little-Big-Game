#ifndef IOBSERVER_H
#define IOBSERVER_H

#include "Event.hh"

template<typename Object>
class IObserver
{
    public:
        virtual bool HasCollide(Event<Object>* e) = 0;
};

#endif // IOBSERVER_H
