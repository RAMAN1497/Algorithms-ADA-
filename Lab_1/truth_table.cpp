#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool a[20];   // Array to store T/F values

// Recursive Backtracking Truth Table Generator
void BTT(int k, int n)
{
    if (k > n)
    {
        // Normally: print a[1..n]
        // Skipped printing for accurate time measurement
        return;
    }

    a[k] = true;      // Assign T
    BTT(k + 1, n);    // Recur

    a[k] = false;     // Assign F
    BTT(k + 1, n);    // Recur
}

int main()
{
    int repetitions = 100;

    cout << "Inputs(n)\tAverageTime(us)\n";

    // Vary input size from 2 to 15
    for (int n = 2; n <= 15; n++)
    {
        long long totalTime = 0;

        // Repeat experiment 100 times
        for (int i = 0; i < repetitions; i++)
        {
            auto start = high_resolution_clock::now();
            BTT(1, n);
            auto end = high_resolution_clock::now();

            totalTime += duration_cast<microseconds>(end - start).count();
        }

        double averageTime = (double)totalTime / repetitions;
        cout << n << "\t\t" << averageTime << endl;
    }

    return 0;
}