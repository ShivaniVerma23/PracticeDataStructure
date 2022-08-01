#include <iostream>

using namespace std;

class Vehicle
{
public:
    virtual void print() = 0;
};

class car : public Vehicle
{
public:
    void print()
    {
        cout << "Car" << endl;
    }
};
class bicycle : public Vehicle
{
public:
    void print()
    {
        cout << "Bicycle" << endl;
    }
};

class factory
{
    Vehicle *object;

public:

    factory(int type)
    {
       switch (type)
       {
       case 1:
          object = new car();
           break;
       case 2:
          object = new bicycle();
           break;
       }
    }
    Vehicle* getVehicle()
    {
        return object;
    }
};

int main()
{
    factory *fp = new factory(1);
    Vehicle* vp = fp->getVehicle();
    vp->print();
    return 0;
}
