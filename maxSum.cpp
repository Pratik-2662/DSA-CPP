#include <iostream>
using namespace std;
int Max = 0;

int calSum(int num)
{
    int sum = 0;
    while (num)
    {
        sum = sum + num % 10;
        num = num / 10;
    }
    return sum;
}

int find(int arr1[], int arr2[], int n1, int n2)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (calSum(arr1[i]) == calSum(arr2[j]))
            {
                int max = arr1[i] + arr2[j];
                if (max > Max)
                {
                    Max = max;
                }
            }
        }
    }
    return Max;
}

int main()
{
    int arr1[] = {10, 20, 30, 47, 50, 63, 70, 1434};
    int arr2[] = {10, 88, 90, 3414, 45, 52, 74, 13};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << find(arr1, arr2, size1, size2);
}