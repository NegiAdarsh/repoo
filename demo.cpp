#include <iostream>
using namespace std;
int partition(int* arr, int s, int e)
{
    int pivot = arr[s], count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    while (s < pivotIndex && e > pivotIndex)
    {
        while (arr[s] <= pivot)
            s++;
        while (arr[e] > pivot)
            e--;
        if (s < pivotIndex && e > pivotIndex)
        {
            swap(arr[s++], arr[e--]);
        }
    }
    return pivotIndex;
}
void quickSort(int* arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pivotind = partition(arr, s, e);
    quickSort(arr, s, pivotind - 1);
    quickSort(arr, pivotind + 1, e);
}
int result(int* arr,int n){
    for (int i = n-1; i > 0; i--)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if((arr[i]+arr[j])&1==0) return arr[i]+arr[j];
        }
    }
    return -1;
}
int main(void)
{
    int n,arr[100001];cin>>n;
    for (int i = 0; i < n; i++) cin>>arr[i];
    quickSort(arr,0,n-1);
    cout<<result(arr,n)<<endl;
    return 0;
}