#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <string>

using namespace std;

class ISerializable
{
    public:
        ISerializable() {};
        virtual ~ISerializable() {};
        virtual string Serialize() = 0;

    protected:

    private:
};

#endif // ISERIALIZABLE_H
