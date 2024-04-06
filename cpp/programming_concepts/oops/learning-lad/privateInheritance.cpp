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
//class Student : private Person
class Student : private Person
{
    public:
        void Display()
        {
            std::cout << "Name of the student is " << name << std::endl;
        }

        void SetStudentName(std::string iname)
        {
            SetName(iname);
        }
};

int main()
{
    Student st;
    st.SetStudentName("John");
    st.Display();

    return 0;
}