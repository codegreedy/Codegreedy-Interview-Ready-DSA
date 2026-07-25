#include <iostream>
using namespace std;

void insertionSort(vector <int> arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int vector<int> arr = {7, 5, 3, 9, 2};
    int n = arr.size():

    insertionSort(arr, n);

    for (int x : arr)
        cout << x << " ";

    return 0;
}
