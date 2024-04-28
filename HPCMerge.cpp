#include <iostream>
#include <omp.h>
using namespace std;

void merge(int *, int, int, int);
void merge_sort(int *arr, int low, int high);

void merge_sort(int *arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

void merge(int *arr, int low, int high, int mid) {
    int i, j, k;
    int *c = new int[high - low + 1];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k++] = arr[i++];
        } else {
            c[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        c[k++] = arr[i++];
    }
    while (j <= high) {
        c[k++] = arr[j++];
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
    delete[] c;
}

int main() {
    omp_set_num_threads(4);
    int myarray[30], num;
    cout << "\nEnter number of elements to be sorted : ";
    cin >> num;
    cout << "\nEnter elements : ";
    for (int i = 0; i < num; i++) {
        cin >> myarray[i];
    }
    merge_sort(myarrayg++ -o HPCMerge -fopenmp HPCMerge.cpp -lstdc++, 0, num - 1);
    cout << "\nSorted array : ";
    for (int i = 0; i < num; i++) {
        cout << myarray[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
g++ -o HPCMerge -fopenmp HPCMerge.cpp -lstdc++

/HPCMerge

Enter number of elements to be sorted : 6

Enter elements : 1 23 34 4 53 5        

Sorted array : 1 4 5 23 34 53 
*/
