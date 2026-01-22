#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;

void insertion_sort(vector<int> &arr)
{ int key,j;
    int n=arr.size();
for(int i=1;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}

}

int main(){
   
    

int repetitions = 100;

    cout << "InputSize\tBest case(ms)\tWorst case(ms)\n";

    for (int n = 1000; n <= 10000; n += 1000) {


 vector<int> original2(n);
        for (int i = 0; i < n; i++)
           { original2[i] = n-i;}

        vector<int> original(n);
        for (int i = 0; i < n; i++)
           { original[i] = i;}

        long long sortedTime = 0;
        long long reversedTime = 0;

        for (int i = 0; i < repetitions; i++) {
            vector<int> arr_sorted = original;

            auto start = high_resolution_clock::now();
           insertion_sort(arr_sorted);
         auto end = high_resolution_clock::now();

            sortedTime += duration_cast<milliseconds>(end - start).count();
        }

        for (int i = 0; i < repetitions; i++) {
            vector<int> arr_reversed= original2;

            auto start = high_resolution_clock::now();
            insertion_sort(arr_reversed);
            auto end = high_resolution_clock::now();

            reversedTime += duration_cast<milliseconds>(end - start).count();
        }

        cout << n << "\t\t"
             << sortedTime / repetitions << "\t\t"
             << reversedTime / repetitions << endl;
    }

    return 0;
}