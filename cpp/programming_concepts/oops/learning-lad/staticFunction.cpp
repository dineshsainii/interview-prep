#include <iostream>

class MyClass {
public:
    static int staticVar; // Static member variable
    int nonStaticVar;     // Non-static member variable

    static void staticFunction() {
        // Static member function can access only other static members
        staticVar = 10;  // OK
        // nonStaticVar = 20;  // Error: Cannot access non-static member
    }

    void nonStaticFunction() {
        // Non-static member function can access both static and non-static members
        staticVar = 30;  // OK
        nonStaticVar = 40;  // OK
    }
};

// Define the static member variable outside the class definition
int MyClass::staticVar = 0;

int main() {
    std::cout << MyClass::staticVar << std::endl;
    MyClass::staticFunction(); // Call static member function without creating an object
    MyClass obj;
    std::cout << MyClass::staticVar << std::endl;
    obj.nonStaticFunction(); // Call non-static member function using an object
    std::cout << MyClass::staticVar << std::endl;
    return 0;
}
