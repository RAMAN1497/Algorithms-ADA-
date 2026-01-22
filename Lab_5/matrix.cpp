#include<iostream>
using namespace std;

#define MAX 100
void addMatrix(int a[MAX][MAX],int b[MAX][MAX],int c[MAX][MAX],int size ){
    for(int i=0;i<size;i++){
       for(int j=0;j<size;j++){
        c[i][j]=a[i][j]+b[i][j];
    } 
    }
}

void multiply(int a[MAX][MAX],int b[MAX][MAX],int c[MAX][MAX],int size){
    if(size==1){
      c[0][0]=a[0][0]*b[0][0];
      return;
    }
    int newsize=size/2;
    int A11[MAX][MAX],A12[MAX][MAX],A21[MAX][MAX],A22[MAX][MAX];
    int B11[MAX][MAX],B12[MAX][MAX],B21[MAX][MAX],B22[MAX][MAX];
    int C11[MAX][MAX],C12[MAX][MAX],C21[MAX][MAX],C22[MAX][MAX];
    int t1[MAX][MAX],t2[MAX][MAX];
for(int i=0;i<newsize;i++){
       for(int j=0;j<newsize;j++){
         A11[i][j]=a[i][j];
        A12[i][j]=a[i][j+newsize];
        A21[i][j]=a[i+newsize][j];
        A22[i][j]=a[i+newsize][j+newsize];

        B11[i][j]=b[i][j];
        B12[i][j]=b[i][j+newsize];
        B21[i][j]=b[i+newsize][j];
        B22[i][j]=b[i+newsize][j+newsize];

    } 
    }

multiply(A11,B11,t1,newsize);
multiply(A12,B21,t2,newsize);
addMatrix(t1,t2,C11,newsize);

multiply(A11,B12,t1,newsize);
multiply(A12,B22,t2,newsize);
addMatrix(t1,t2,C12,newsize);

multiply(A21,B11,t1,newsize);
multiply(A22,B21,t2,newsize);
addMatrix(t1,t2,C21,newsize);

multiply(A21,B12,t1,newsize);
multiply(A22,B22,t2,newsize);
addMatrix(t1,t2,C22,newsize);


 for(int i=0;i<newsize;i++){
       for(int j=0;j<newsize;j++){
      c[i][j]= C11[i][j];
        c[i][j+newsize]=C12[i][j];
        c[i+newsize][j]=C21[i][j];
        c[i+newsize][j+newsize]=C22[i][j];

    } 
    }


}
int main(){
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX],size;
    cout<<"Enter the size of matrix";
    cin>>size;
    for(int i=0;i<size;i++){
       for(int j=0;j<size;j++){
        cin>>a[i][j];
    } 
    }
    for(int i=0;i<size;i++){
       for(int j=0;j<size;j++){
        cin>>b[i][j];
    } 
    }
    multiply(a,b,c,size);
     for(int i=0;i<size;i++){
       for(int j=0;j<size;j++){
        cout<<c[i][j]<<" ";
    } 
    cout<<endl;
    }
}
