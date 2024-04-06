#include <iostream>
#include <string>

class Person
{
    private:
        uint32_t salary;
    public:
        int age;
        std::string name;

        Person(std::string iname = "John", int iage = 16, uint32_t isalary = 1000) : \
        name(iname), age(iage), salary(isalary) {}
        void DisplayDetails()
        {
            std::cout << "Name is " << this->name << std::endl;
            std::cout << "Age is " << this->age << std::endl; 
            std::cout << "Salary is " << this->salary << std::endl;
        }
        void DisplayAge();
        void DisplaySalaryDetails();
        void SetSalary(uint32_t isalary);
};

void Person::DisplayAge()
{
    std::cout << "Age of this person is " << this->age << std::endl;
}

void Person::DisplaySalaryDetails()
{   
    std::cout << "His/her Salary is " << salary << std::endl;
}
void Person::SetSalary(uint32_t isalary)
{
    salary = isalary;
}


int main()
{
    Person p;
    // p.name = "John";
    // p.age = 23;
    p.DisplayDetails();
    Person *newPerson = new Person("Dinesh", 32);
    // newPerson->name = "Doe";
    // newPerson->age = 11;
    newPerson->SetSalary(100000);
    newPerson->DisplayDetails();
    newPerson->DisplayAge();
    newPerson->DisplaySalaryDetails();
    return 0;
}