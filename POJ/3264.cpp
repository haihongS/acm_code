#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e6+9;

struct II
{
    int v;
    int lch,rch;
}tree1[4*maxn],tree2[4*maxn];

int n,q;
int num[maxn];

int build1(int node,int l,int r);
int build2(int node,int l,int r);
int query1(int node,int l,int r,int L,int R);
int query2(int node,int l,int r,int L,int R);


int main()
{
    while(~scanf("%d%d",&n,&q))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        build1(0,0,n);
        build2(0,0,n);

        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--,b--;
            int maxx=query2(0,0,n,a,b+1);
            int minn=query1(0,0,n,a,b+1);
            printf("%d\n",maxx-minn);
        }
    }
    return 0;
}

// q max
int query2(int node,int l,int r,int L,int R)
{
    if(R<=l || L>=r) return 0;
    if(L<=l && r<=R)
    {
        return tree2[node].v;
    }
    int mid=l+(r-l)/2;
    int u=query2(2*node+1,l,mid,L,R);
    int v=query2(2*node+2,mid,r,L,R);
    return max(u,v);
}

int build2(int node,int l,int r)
{
    if(l+1==r)
    {
        tree2[node].v=num[l];return num[l];
    }
    int mid=l+(r-l)/2;
    tree2[node].lch=2*node+1,tree2[node].rch=2*node+2;

    int u=build2(2*node+1,l,mid),v=build2(2*node+2,mid,r);
    tree2[node].v=max(u,v);
    return tree2[node].v;
}

// q min
int query1(int node,int l,int r,int L,int R)
{
    if(R<=l || L>=r) return inf;
    if(L<=l && r<=R)
    {
        return tree1[node].v;
    }
    int mid=l+(r-l)/2;
    int u=query1(2*node+1,l,mid,L,R);
    int v=query1(2*node+2,mid,r,L,R);
    return min(u,v);
}

int build1(int node,int l,int r)
{
    if(l+1==r)
    {
        tree1[node].v=num[l];return num[l];
    }
    int mid=l+(r-l)/2;
    tree1[node].lch=2*node+1,tree1[node].rch=2*node+2;
    int u=build1(2*node+1,l,mid),v=build1(2*node+2,mid,r);
    tree1[node].v=min(u,v);
    return tree1[node].v;
}


