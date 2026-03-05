#include <iostream>
using namespace std;

#define INF 999
#define MAX 100

int main()
{
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;

    int cost[MAX][MAX];

    cout<<"Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
                cost[i][j]=INF;
        }

    int near[MAX], t[MAX-1][2];
    int mincost=0;

    int k=0,l=0,min=INF;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(cost[i][j] < min)
            {
                min = cost[i][j];
                k=i;
                l=j;
            }

    mincost = cost[k][l];
    t[0][0]=k;
    t[0][1]=l;

    for(int i=0;i<n;i++)
    {
        if(cost[i][l] < cost[i][k])
            near[i]=l;
        else
            near[i]=k;
    }

    near[k]=near[l]=-1;

    for(int i=1;i<n-1;i++)
    {
        min=INF;
        int j;

        for(int k=0;k<n;k++)
        {
            if(near[k]!=-1 && cost[k][near[k]]<min)
            {
                min=cost[k][near[k]];
                j=k;
            }
        }

        t[i][0]=j;
        t[i][1]=near[j];
        mincost+=cost[j][near[j]];

        near[j]=-1;

        for(int k=0;k<n;k++)
        {
            if(near[k]!=-1 && cost[k][near[k]] > cost[k][j])
                near[k]=j;
        }
    }

    cout<<"Edges of Minimum Spanning Tree:\n";
    for(int i=0;i<n-1;i++)
        cout<<t[i][0]<<" - "<<t[i][1]<<endl;

    cout<<"Minimum cost = "<<mincost;

    return 0;
}