#ifndef EVENT_H
#define EVENT_H

template<typename Object>
class Event
{
    public:
        Event(Object* obj)
        {
            this->_obj = obj;
        };

        virtual ~Event()
        {
            delete this->_obj;
        };

        Object* GetInfo()
        {
            return this->_obj;
        };

    private:
        Object* _obj;
};

#endif // EVENT_H
