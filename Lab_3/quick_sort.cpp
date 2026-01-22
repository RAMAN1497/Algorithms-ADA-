#include <iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace chrono;
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);
        quick_sort(arr, low, part - 1);
        quick_sort(arr, part + 1, high);
    }
}

int main() {
    int repetitions = 100;
int target;
    cout << "InputSize\tTime(ns)\n";

    for (int n = 1000; n <= 10000; n += 1000) {

        vector<int> original(n);
        for (int i = 0; i < n; i++)
           { original[i] = rand();}

        long totalTime = 0;

        for (int i = 0; i < repetitions; i++) {
            vector<int> arr= original;
            auto start = high_resolution_clock::now();
          quick_sort(arr,0,n-1);
         auto end = high_resolution_clock::now();

            totalTime += duration_cast<nanoseconds>(end - start).count();
        }
cout << n << "\t\t" << totalTime / repetitions << endl;

    }
}
