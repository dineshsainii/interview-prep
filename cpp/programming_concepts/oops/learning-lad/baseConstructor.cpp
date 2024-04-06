#include <iostream>

class Parent
{   
    protected:
        int height;

    public:
        Parent(int iheight) : height(iheight) {}
};

class Student : public Parent
{
    public:
        std::string name;

        Student (std::string iname, int iheight = 10) :name(iname), Parent(iheight) {}

        void DisplayDetails()
        {
            std::cout << "Name is : " << name << " height :" << height << std::endl;
        } 
};


int main()
{
    Student st("John", 177);
    st.DisplayDetails();

    return 0;
}