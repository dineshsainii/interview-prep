#include <iostream>

// class B;
class A
{
    private:
        int dataA;

    public:
        A(int idata): dataA(idata) {}
        
        friend class B;
        
        void Display()
        {
            std::cout << "Data is in class A " << dataA << std::endl;
        }
};

class B
{
    private:
        int dataB;
    
    public:
        B(int idata) : dataB(idata) {}

        void Display()
        {
            std::cout << "Data in class B " << dataB << std::endl;
        }

        void SetValueInA(A& obj, int newData)
        {
            obj.dataA = newData;
        }
};

int main()
{
    A objA(5);
    objA.Display();
    B objB(10);
    objB.Display();
    objB.SetValueInA(objA, 20);
    objA.Display();

    return 0;
}