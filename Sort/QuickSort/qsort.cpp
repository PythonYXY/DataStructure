#include <iostream>
#include <cstdio>
using namespace std;


int Partition(int low, int high, int arr[])
{
    int pivot = arr[high];
    int pivotPos = low;
    int i;
    for(i = low; i < high; i++){
        if(arr[i] < pivot){
            if(i != pivotPos) {swap(arr[i], arr[pivotPos]);}
            pivotPos++;
        }
    }
    swap(arr[high], arr[pivotPos]);
    return pivotPos;

}

void Merge(int low, int high, int arr[])
{
    if(low < high){
        int mid = Partition(low, high, arr);
        Merge(low, mid - 1, arr);
        Merge(mid + 1, high, arr);
    }
}


int main()
{
    freopen("data.dat", "r", stdin);
    freopen("qsort_result.dat", "w", stdout);
    int pos = 0;
    int num;
    int arr[10005];
    while(cin >> num){
        arr[pos++] = num;
    }
    Merge(0, pos - 1, arr);
    for(int i = 0; i < pos; i++) cout << arr[i] << endl;;
    return 0;
}
