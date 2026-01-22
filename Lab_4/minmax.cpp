#include<iostream>
using namespace std;

void minmax(int arr[],int low,int high,int &min,int &max)
{
    if(low==high){
min=max=arr[low];
return ;
    }

    if (low==high-1){
        if(arr[low]<arr[high]){
         min=arr[low];
         max=arr[high];}
        else{
         max=arr[low];
         min=arr[high];
        }
    return;

    }
int a,b,c,d;
int mid=(low+high)/2;
minmax(arr,low,mid,a,b);
minmax(arr,mid+1,high,c,d);
if(a<c){
    min=a;
}
else{
    min=c;
}
if(b<d){
    max=d;
}
else{
    max=b;
}
}

int main(){
    int n,i;
    cout<<"Enter the value of n:";
    cin>>n;
    int *arr= new int[n];

    for(i=0;i<n;i++){
        cin>>arr[i];
    }
     int min,max;
     minmax(arr,0,n-1,min,max);
     cout<<min<<" "<<max<<endl;

}