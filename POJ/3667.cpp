#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=5e4+9;
const double eps=1e-9;
const double inf=1e8;

int sum[4*maxn],lsum[4*maxn],rsum[4*maxn],lazy[4*maxn];

int build(int node,int l,int r);
int query(int node,int l,int r,int v);
int update(int node,int l,int r,int L,int R,int v);
int push_down(int node,int l,int r);
int push_up(int node,int l,int r);

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		build(0,1,n);
		while(m--)
		{
			int op;
			scanf("%d",&op);
			if(op==1)
			{
				int d;
				scanf("%d",&d);
				int ans;
				if(sum[0]<d)
					ans=0;
				else
					ans=query(0,1,n,d);
				printf("%d\n",ans);
				if(ans!=0)
					update(0,1,n,ans,ans+d-1,1);
			}
			else
			{
				int x,d;
				scanf("%d%d",&x,&d);
				update(0,1,n,x,x+d-1,0);
			}
		}
	}
	return 0;
}

int push_up(int node,int l,int r)
{
	lsum[node]=lsum[2*node+1];
	rsum[node]=rsum[2*node+2];
	int mid=l+(r-l)/2;
	if(lsum[node]==mid-l+1)
		lsum[node]+=lsum[2*node+2];
	if(rsum[node]==r-mid)
		rsum[node]+=rsum[2*node+1];
	
	sum[node]=max(max(sum[2*node+1],sum[2*node+2]),rsum[2*node+1]+lsum[2*node+2]);
	return 0;
}

int push_down(int node,int l,int r)
{
	if(lazy[node]!=-1)
	{
		lazy[2*node+1]=lazy[2*node+2]=lazy[node];
		if(lazy[node]==1)
		{
			sum[2*node+1]=lsum[2*node+1]=rsum[2*node+1]=0;
			sum[2*node+2]=lsum[2*node+2]=rsum[2*node+2]=0;
		}
		else
		{
			int mid=l+(r-l)/2;
			sum[2*node+1]=lsum[2*node+1]=rsum[2*node+1]=mid-l+1;
			sum[2*node+2]=lsum[2*node+2]=rsum[2*node+2]=r-mid;
		}
		lazy[node]=-1;
	}
	return 0;
}

int update(int node,int l,int r,int L,int R,int v)
{
	if(L<=l && r<=R)
	{
		if(v==0)
			sum[node]=lsum[node]=rsum[node]=r-l+1;
		else if(v==1)
			sum[node]=lsum[node]=rsum[node]=0;
		lazy[node]=v;
		return 0;
	}
	if(r<L || R<l) return 0;
	push_down(node,l,r);
	int mid=l+(r-l)/2;
	update(2*node+1,l,mid,L,R,v);
	update(2*node+2,mid+1,r,L,R,v);
	push_up(node,l,r);
	return 0;
}

int query(int node,int l,int r,int v)
{
	if(l==r) return l;
	push_down(node,l,r);
	int mid=l+(r-l)/2;
	if(sum[2*node+1]>=v)
		return query(2*node+1,l,mid,v);
	else if(rsum[2*node+1]+lsum[2*node+2]>=v)
		return mid-rsum[2*node+1]+1;
	else
		return query(2*node+2,mid+1,r,v);
}

int build(int node,int l,int r)
{
	sum[node]=lsum[node]=rsum[node]=r-l+1;
	lazy[node]=-1;
	if(l==r) return 0;
	int mid=l+(r-l)/2;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	return 0;
}

