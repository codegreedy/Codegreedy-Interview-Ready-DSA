#include <iostream>
using namespace std;

void bubbleSort(vector<int> arr, int n)
{
    for (int pass = 1; pass <= n - 1; pass++)
    {
        for (int j = 0; j < n - pass; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    vector arr = {5, 3, 8, 4, 2};
    int n = arr.size();

    bubbleSort(arr, n);

    for (int x : arr)
        cout << x << " ";

    return 0;
}
