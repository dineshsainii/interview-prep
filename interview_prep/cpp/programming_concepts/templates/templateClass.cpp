#include <iostream>
template<int N>
class Array
{
    private:
        int m_array[N];

    public:
        int GetSize() const {return N;}
};

int main()
{
    Array<10> arr;
    std::cout << arr.GetSize() << std::endl;
    return 0;
}