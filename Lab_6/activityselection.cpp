#include<iostream>
#include<algorithm>
#define MAX 10000
using namespace std;
struct Pair{
    int start;
    int finish;
    
};

bool compare(Pair a,Pair b){
    return a.finish<b.finish;
}
void activity(Pair arr[],int n){
      sort(arr,arr+n,compare);
      cout<<"Activity selection for n="<<n<<endl;
          cout<<"Starting time\tFinsh Time"<<endl;

      cout<<arr[0].start<<" \t\t "<<arr[0].finish<<endl;
      int i=0;
     for(int j=1;j<n;j++){
        if(arr[j].start>=arr[i].finish){
            cout<<arr[j].start<<" \t\t"<<arr[j].finish<<endl;
            i=j;
        }

     }
}
int main() {
int n;
for(int i=10;i<=50;i+=10){
  n=i;

Pair arr[MAX];
 for (int i = 0; i < n; i++)
            { arr[i].start = rand();
            arr[i].finish=rand();}
   
     activity(arr, n);
            }
    return 0;
}