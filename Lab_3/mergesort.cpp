#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

void merge(vector<int> &arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++) left[i] = arr[start + i];
    for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

void merge_sort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
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
            merge_sort(arr, 0,n );
         auto end = high_resolution_clock::now();

            totalTime += duration_cast<nanoseconds>(end - start).count();
        }
cout << n << "\t\t" << totalTime / repetitions << endl;

    }
 
        
      
}
