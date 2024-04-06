#include <iostream>
#include <vector>

void bubble(std::vector<int> &arr, int n)
{
    if (n==1) // single element is always sorted
        return;
    bool swapped = false;
    for (int i = 0; i<n-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            std::swap(arr[i], arr[i+1]);
            swapped  = true;
        }
    }
    if (!swapped)
        return;
    bubble(arr, n-1);
}

int main()
{
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubble(arr, arr.size());

    for(auto x : arr)
    {
        std::cout << x << std::endl;
    }
    return 0;
}