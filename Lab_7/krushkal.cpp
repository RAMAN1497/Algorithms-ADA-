#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u,v,w;
};

int parent[100];

int findSet(int i)
{
    while(parent[i] > 0)
        i = parent[i];
    return i;
}

void unionSet(int i,int j)
{
    parent[j] = i;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int n,e;
    cout<<"Enter number of vertices and edges: ";
    cin>>n>>e;

    Edge edge[100];

    cout<<"Enter edges (u v weight):\n";
    for(int i=0;i<e;i++)
        cin>>edge[i].u>>edge[i].v>>edge[i].w;

    sort(edge, edge+e, cmp);

    for(int i=1;i<=n;i++)
        parent[i] = -1;

    int count = 0;
    int mincost = 0;

    cout<<"Edges in MST:\n";

    for(int i=0;i<e && count<n-1;i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;

        int j=findSet(u);
        int k=findSet(v);

        if(j!=k)
        {
            cout<<u<<" - "<<v<<" : "<<edge[i].w<<endl;
            mincost += edge[i].w;
            unionSet(j,k);
            count++;
        }
    }

    cout<<"Minimum Cost = "<<mincost;

    return 0;
}