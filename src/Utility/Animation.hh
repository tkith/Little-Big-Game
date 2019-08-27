#ifndef ANIMATION_H
#define ANIMATION_H

using namespace std;

class Animation
{
    public:
        Animation(double, double);
        virtual ~Animation();


    protected:

    private:

        int actualFrame = 0;
};

#endif // ANIMATION_H
