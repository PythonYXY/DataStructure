#include <iostream>
#include <cstring>
#include <random>
#include <cstdio>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int MAX_SIZE = 12000;

int arr[MAX_SIZE];


void Insert(int x)
{
    int i = x / 2;
    int j = i;
    do{
        if(arr[j] == -1) {arr[j] = x; return;}
        j = (j + 1) % MAX_SIZE;
    }while(j != i);
}






int main()
{
    memset(arr, -1, sizeof(arr));
    freopen("RandomNums.dat", "r", stdin);
    freopen("Hash_table_result.dat", "w", stdout);
    int x;
    while(cin >> x) Insert(x);

    for(int i = 0; i < MAX_SIZE; i++) cout << i << ": " << arr[i] << endl;

    /*
    // Generate different random numbers
    freopen("RandomNums.dat", "w", stdout);
    srand((unsigned)time(NULL));
    int tmp[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++) tmp[i] = i;
    int k = MAX_SIZE;
    while(k > 0){
        int temp = rand() % k;
        swap(tmp[k - 1], tmp[temp]);
        k--;
    }

    for(int i = 0; i < MAX_SIZE; i++) cout << tmp[i] << endl;
    */
    return 0;
}
