#include <iostream>

using namespace std;

class Singleton
{
    static Singleton *s_instance;
    Singleton()
    {
    }
    Singleton(const Singleton &)
    {
    }

public:
    static Singleton *getInstance()
    {
        if (s_instance == NULL)
            s_instance = new Singleton();
        return s_instance;
    }
};

Singleton *Singleton::s_instance = 0;

int main()
{
    Singleton *obj = Singleton::getInstance();

    cout << obj << endl;

    Singleton *obj2 = Singleton::getInstance();
    cout << obj << endl;

    return 0;
}