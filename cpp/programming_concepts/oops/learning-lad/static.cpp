#include <iostream>

class Person
{
    public:
        static int human_count;

    Person()
    {
        human_count++;
    }

    void DisplayHumanCount()
    {
        std::cout << "Number of instantiated humans as of now is " << human_count << std::endl;
    }


};

int Person::human_count = 0;

int main()
{
    Person adam;
    adam.DisplayHumanCount();
    Person eve;
    eve.DisplayHumanCount();
    Person adamSon;
    adamSon.DisplayHumanCount();
    return 0;
}