#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Given recursive function
int findTips(double v)
{
    if (v < 1.0)
        return 0;

    return 1 + findTips(v - 0.425*v);
}

int main() {
int v;
   cout<<"Enter the velocity:";
   cin>>v;
          cout<<  findTips(v);
         
    

    return 0;
}