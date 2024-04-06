#include <iostream>

class Person
{
    public:
        virtual void Introduce()
        {
            std::cout << "Person intro" << std::endl;
        }
};

class Student : public Person
{
    public:
        void Introduce() 
        {
            std::cout << "Student intro" << std::endl;
        }
};

class Monitor : public Student
{
    public:
        void Introduce()
        {
            std::cout << "Monitor intro" << std::endl;
        }
};

void DisplayDetails(Person *p)
{
    p->Introduce();
}

int main()
{
    // Student st;
    Monitor st;
    DisplayDetails(&st);
    return 0;
}