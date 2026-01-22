#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {

    int repetitions = 100;

    cout << "InputSize\tBubbleSort(ms)\tSelectionSort(ms)\n";

    for (int n = 1000; n <= 7000; n += 1000) {

        vector<int> original(n);
        for (int i = 0; i < n; i++)
            original[i] = rand() % 100000;

        long long bubbleTime = 0;
        long long selectionTime = 0;

        // Bubble Sort Timing
        for (int i = 0; i < repetitions; i++) {
            vector<int> arr = original;

            auto start = high_resolution_clock::now();
            bubbleSort(arr);
            auto end = high_resolution_clock::now();

            bubbleTime += duration_cast<milliseconds>(end - start).count();
        }

        // Selection Sort Timing
        for (int i = 0; i < repetitions; i++) {
            vector<int> arr = original;

            auto start = high_resolution_clock::now();
            selectionSort(arr);
            auto end = high_resolution_clock::now();

            selectionTime += duration_cast<milliseconds>(end - start).count();
        }

        cout << n << "\t\t"
             << bubbleTime / repetitions << "\t\t"
             << selectionTime / repetitions << endl;
    }

    return 0;
}
