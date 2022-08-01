#include <iostream>

using namespace std;

/*class Base
{
public:
   virtual void print()
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    Base* obj = new Derived();
    for (int i=0; i<10; i++)
    {
        Base* obj = new Base();
    }
    obj -> print();

    delete[] obj;
    return 0;
}*/

class S
{
    S()
    {
    }
    S(const S &)
    {
    }
    S* operator=(const S &);
    static S *obj;

public:
    static S *get_instance()
    {
        return new S();
    }
    S *operator->()
    {
        return obj;
    }
    void print()
    {
        cout << "SS" << endl;
    }
};

class D: public S
{
    public:
    void pp()
    {
        cout <<"D"<<endl;
    }

};

S *S::obj = 0;

int main()
{
    S *ob = S::get_instance();
    ob->print();

  //  D* ob = new D();
    return 0;
}
