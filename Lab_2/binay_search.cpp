#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
 
int  binary_search(vector<int>& arr,int low,int high,int target){
    if(low>high) return -1;
    int mid=low+(high-low)/2;
    if(mid==target) return mid;
    else if(mid>target) return binary_search(arr,low,mid-1,target);
    else return binary_search(arr,mid+1,high,target);
}

int main(){
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
           target=rand();
            auto start = high_resolution_clock::now();
          binary_search(arr,0,n,target);
         auto end = high_resolution_clock::now();

            totalTime += duration_cast<nanoseconds>(end - start).count();
        }
cout << n << "\t\t" << totalTime / repetitions << endl;

    }
    return 0;
}