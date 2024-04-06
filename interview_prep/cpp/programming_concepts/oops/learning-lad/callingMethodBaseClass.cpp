#include <iostream>

class Base
{
    public:
        void Introductoin()
        {
            std::cout << "Base class introduction" << std::endl;
        }
};

class Derived : public Base
{
    public:
        void Introduction()
        {
            std::cout << "Derived class Introduction" << std::endl;
        }
};

void WhoIsThis(Base p)
{
    p.Introductoin();
}

int main()
{
    Derived d;
    d.Introduction();
    WhoIsThis(d);
    return 0;
}