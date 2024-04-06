#include <iostream>

class Base
{
    public:
        void Introduction()
        {
            std::cout << "Base class intro method" << std::endl;
        }
};

class Derived : public Base
{
    public:
        void Introduction()
        {
            std::cout << "Derived class intro method" << std::endl;
        }
};

int main()
{
    // Base *ptr = new Derived();
    // ptr->Introduction();
    // ptr->Base::Introduction();
    Derived obj;
    obj.Introduction();

    return 0;
}