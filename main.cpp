/***********************************************
Author        :shootPlane
Created Time  :2016年03月25日 星期五 15时04分56秒
File Name     :main.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long LL;
const int maxn=1e5+9;
const int inf=1e9+9;

int n,q;
LL num[maxn], sum[4*maxn],flag[4*maxn];

int build(int node,int l,int r);
LL query(int node,int l,int r,int L,int R);
int update(int node,int l,int r,int L,int R,LL v);
int push(int node);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&q))
	{
		for(int i=0;i<n;i++) scanf("%lld",&num[i]);
		build(0,1,n);
		for(int i=0;i<q;i++)
		{
			char op;
			scanf("%c",&op);
			int a,b,c;
			if(op=='Q')
			{
				scanf("%d%d",&a,&b);
				LL go=query(0,1,n,a,b);
				printf("%lld\n",go);
			}
			else
			{
				scanf("%d%d%d",&a,&b,&c);
				update(0,1,n,a,b,c);
			}
		}
	}
    return 0;
}


int update(int node,int l,int r,int L,int R,LL v)
{
	if(L<=l && r<=R)
	{
		sum[node]+=v;
		flag[node]+=v;
		return 0;
	}
	int mid=l+(r-l)/2;
	if(L<=mid) update(2*node+1,l,mid,L,R,v);
	if(R>mid) update(2*node+2,mid+1,r,L,R,v);
	sum[node]=sum[2*node+1]+sum[2*node+2];
	return 0;
}


int push(int node)
{
	if(flag[node]!=0)
	{
		sum[2*node+1]+=flag[node];
		flag[2*node+1]+=flag[node];
		sum[2*node+2]+=flag[node];
		flag[2*node+2]+=flag[node];
		flag[node]=0;
	}
	return 0;
}

LL query(int node,int l,int r,int L,int R)
{
	push(node);
	if(L<=l && r<=R)
	{
		return sum[node];
	}
	int mid=l+(r-l)/2;
	LL ans=0;
	if(L<=mid)
	{
		if(R>=mid)
		{
			ans+=query(2*node+1,l,mid,L,mid);
			ans+=query(2*node+2,mid+1,r,mid+1,R);
		}
		else
		{
			ans+=query(2*node+1,l,mid,L,R);
		}
	}
	else
	{
		ans+=query(2*node+2,mid+1,r,L,R);
	}
	return ans;
}

int build(int node,int l,int r)
{
	if(l==r)
	{
		sum[node]=num[l];
		flag[node]=0;
		return 0;
	}
	int mid=l+(r-l)/2;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	sum[node]=sum[2*node+1]+sum[2*node+2];
	flag[node]=0;
	return 0;
}
