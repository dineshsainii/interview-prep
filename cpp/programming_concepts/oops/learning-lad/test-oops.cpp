#include <iostream>

class Human
{
        int age;
        std::string name;
    public:

        Human(std::string iname, int iage) : age(iage), name(iname) {}

        friend void GetDetails(Human person);

};

void GetDetails(Human person)
{
    std::cout << person.name << " is " << person.age << " years old." << std::endl;
}

int main()
{
    Human *din = new Human("Dinesh", 32);
    GetDetails(*din);
    return 0;
}