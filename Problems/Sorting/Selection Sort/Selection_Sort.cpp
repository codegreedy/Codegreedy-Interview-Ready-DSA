#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        int min = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[i];
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for (int x : arr)
        cout << x << " ";

    return 0;
}
