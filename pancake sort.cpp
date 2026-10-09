#include <iostream>
#define N 7
using namespace std;

int findlargest (int a[], int size){
    int largest = a[0], index = 0;
    for (int i = 1; i < size; i++){
        if (a[i] > largest){
            largest = a[i];
            index = i;
        }
    }
    return index;
}

void flip (int a[], int k) {
    int left = 0, right = k-1;
    while (left < right){
        swap (a[left], a[right]);
        left++;
        right--;
    }
}

void pancake_sort(int a[]){
    for (int size = N; size > 1; size--){
        int temp = findlargest (a, size);
        flip (a, temp+1);
        flip (a, size);
    }
}

int main()
{
    int a[] = {2,5,8,6,9,7,1}; int largest, n = 7;

    pancake_sort (a);

    for (int i = 0; i < N; i++){
        cout<<a[i]<<' ';
    }


    return 0;
}
