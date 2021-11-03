#include <iostream>
using namespace std;
bool isHeap(int arr[], int size)
{
    for (int i = 0; i < (size / 2 - 1); i++)
    {
        if ((arr[i] > arr[2 * i + 1] || arr[i] > arr[2 * i + 2]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int arr[] = {10, 15, 14, 25, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    isHeap(arr, size) ? cout << "Yes it is Heap" : cout << "No it is not Heap";
}