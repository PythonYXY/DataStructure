#include <iostream>
#include <cstdio>
using namespace std;

void ShellSort(int low, int high, int arr[])
{
    int gap = high - low + 1;
    int tmp;
    do{
        gap = gap / 3 + 1;
        for(int i = low + gap; i <= high; i++){
            if(arr[i] < arr[i - gap]){
                tmp = arr[i];
                int j = i - gap;

                do{
                    arr[j + gap] = arr[j];
                    j = j - gap;
                }while(j >= low && tmp < arr[j]);
                arr[j + gap] = tmp;
            }
        }
    }while(gap > 1);
}


int main()
{
    freopen("data.dat", "r", stdin);
    freopen("ShellSort_result.dat", "w", stdout);
    int pos = 0;
    int num;
    int arr[10005];
    while(cin >> num){
        arr[pos++] = num;
    }
    ShellSort(0, pos - 1, arr);
    for(int i = 0; i < pos; i++) cout << arr[i] << endl;;
    return 0;
}
