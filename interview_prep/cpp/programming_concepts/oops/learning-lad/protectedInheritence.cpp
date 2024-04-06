#include <iostream>

class Person
{
    protected:
        std::string name;
    public:
        void SetName(std::string iname)
        {
            name = iname;
        }
};

class Student : protected Person
{
    public:
        void SetStudentName(std::string iname)
        {
            SetName(iname);
        }
        void Display()
        {
            std::cout << "Name is " << name << std::endl;
        }
};

int main()
{
    Student anil;
    anil.SetStudentName("Anil");
    anil.Display();
    return 0;
}