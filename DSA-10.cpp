#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
}

void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int LeftArray[n1], RightArray[n2];

    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0;      /* initial index of first sub-array */
    j = 0;      /* initial index of second sub-array */
    k = beg;    /* initial index of merged sub-array */

    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int partition(int a[], int start, int end)
{
    int pivot = a[end]; // pivot element
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;
    return (i + 1);
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int p = partition(a, start, end); // p is the partitioning index
        quickSort(a, start, p - 1);
        quickSort(a, p + 1, end);
    }
}

void PRINT(int Arr[], int n){
    for(int i=0; i<n; i++){
        cout<<Arr[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"How Many Numbers: ";
    cin>>n;
    int A[n];
    int B[n];
    int C[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
        B[i]=C[i]=A[i];
    }
    cout << "Bubble Sort: \n";
    bubbleSort(A, n);
    PRINT(A,n);
    cout << "Merge Sort: \n";
    mergeSort(B, 0, n);
    PRINT(B, n);
    cout << "Quick Sort: \n";
    quickSort(C, 0, n);
    PRINT(C, n);
    return 0;
}