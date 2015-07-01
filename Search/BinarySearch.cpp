#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_SIZE = 10005;

int arr[MAX_SIZE];

int Search(int low, int high, int x)
{
    int mid = -1;
    if(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == x) return mid;
        else if(x < arr[mid]) mid =  Search(low, mid - 1, x);
        else mid = Search(mid + 1, high, x);
    }

    return mid;
}


int main()
{
    freopen("nums.dat", "r", stdin);
    int x;
    int i = 0;
    while(cin >> x){
        arr[i++] =  x;
    }

    cout << "the position of 8369 is " << Search(0, i - 1, 8369) << endl;
    cout << "the position of 8370 is " << Search(0, i - 1, 8370) << endl;
    cout << "the position of 9997 is " << Search(0, i - 1, 9997) << endl;
    return 0;
}
