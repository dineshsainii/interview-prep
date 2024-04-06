#include <iostream>
#include <vector>

void StableSelection(std::vector<int> &arr)
{
    int min_idx;
    int count = arr.size();
    for (int i = 0; i < count-1; i++)
    {   
        min_idx = i;
        for (int j = i+1; j < count; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if(min_idx!=i)
        {
            int key = arr[min_idx];
            for (int k = min_idx; k > i; k--)
            {
                arr[k] = arr[k-1];
            }
            arr[i] = key;
        }
    }
    
}

int main()
{
    std::vector<int> arr = {44, 15, 23, 12, 44, 91};
    StableSelection(arr);

    for (auto x : arr)
    {
        std::cout << x << " ";
    }

    return 0;
}