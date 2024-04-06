#include <iostream>
#include <array>

void Selection_Sorting(std::array<int, 7> &arr)
{
    int smallest_num_index;
    for (int i = 0; i<arr.size()-1;i++)
    {
        smallest_num_index = i; 
        for (int j = i+1; j<arr.size(); j++)
        {   
            if (arr[j] < arr[smallest_num_index])
                smallest_num_index = j;
        }
        std::swap(arr[i],arr[smallest_num_index]);
    }
}

int main()
{
    std::array<int, 7> arr = {21, 14, 2, 12, 16, 41, 32};
    Selection_Sorting(arr);
    for (auto num : arr)
    {
        std::cout << num << std::endl;
    }
    return 0;
}