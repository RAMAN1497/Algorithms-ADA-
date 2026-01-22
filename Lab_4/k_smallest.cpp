#include<iostream>
using namespace std;

int partition(int arr[],int low,int high)
{
    int i=low+1;
    int j=high;
    int p=arr[low];
    while(i<=j)
{
    while(i<=j && arr[i]<p){
        i++;
    }
    while(i<=j && arr[j]>p){
        j--;
    }
    if(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    
}
arr[low]=arr[j];
    arr[j]=p;

return j;
}


int smallest(int arr[],int low,int high,int k){
int j=partition(arr,low,high);
if(j+1==k) return arr[j];
else if(j+1<k){
    return smallest(arr,j+1,high,k);
}
else{
    return smallest(arr,low,j-1,k);
}
}

int main(){
      int n;
      cout<<"Enter the size of arr:";
      cin>>n;
int *arr= new int(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int k;
cout<<"Enter the value of k:";
cin>>k;
cout<<smallest(arr,0,n-1,k);
return 0;
}