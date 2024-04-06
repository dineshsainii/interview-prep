#include <iostream>
#include <vector>

void Bubble(std::vector<int> &arr)
{
	int size = arr.size();
	for (int i = 0; i<size-1; i++)
	{
		for (int j = 0; j<size-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				std::swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main()
{
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  Bubble(arr);
  for (auto x : arr)
  {
	std::cout << x << std::endl;
  }
  return 0;
}
