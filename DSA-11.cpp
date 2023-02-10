#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(void)
{
    // int arr[] = {2, 3, 4, 10, 40};
    // int x = 10;
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int result = binarySearch(arr, 0, n - 1, x);
    int n, value, position;
    cout << "Enter Number Of Array Elements: ";
    cin >> n;
    int Arr[n];
    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    cout << "Enter Value To Search In Array: ";
    cin >> value;
    position = binarySearch(Arr, 0, n - 1, value);
    if (position == -1)
    {
        cout << "Element Not Found ";
    }
    else
    {
        cout << value << " Is At Array Position= " << position;
    }
    return 0;
}
