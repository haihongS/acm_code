/* ***********************************************
Author        :shootPlane
Created Time  :2016年03月26日 星期六 16时43分31秒
File Name     :1990.cpp
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
#define LL long long
const int maxn=2e4+9;
const int inf=1e9+9;

struct II
{
	LL v,x;
}num[maxn];

LL sum[maxn];
int cnt[maxn];

int cmp(II a,II b);
int lowbit(int x);

LL getsum(int x);
int addsum(int x,LL v);

int getcnt(int x);
int addcnt(int x,int v);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(~scanf("%d", &n)){
	for(int i=0;i<n;i++) scanf("%lld%lld",&num[i].v,&num[i].x);
	sort(num,num+n,cmp);
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	LL ans=0;
	for(int i=0;i<n;i++)
	{
		LL x=num[i].x, v=num[i].v;
		LL pre=getsum((int)x),cc=(LL)getcnt((int)x);
		//ans+=(cc*x-pre)*v+(getsum(maxn)-pre-x*((LL)(i)-cc))*v;
		ans+=v*(getsum(maxn)-pre*2+2*x*cc-x*(LL)(i));'
		//ans+=v*(cc*x-pre+(getsum(maxn)-pre)-((LL)(i)-cc)*x);
		addsum((int)x,x);
		addcnt((int)x,1);
	}
	printf("%lld\n",ans);
	}
    return 0;
}

int addcnt(int x,int v)
{
	while(x<maxn)
	{
		cnt[x]+=v;
		x+=lowbit(x);
	}
	return 0;
}

int getcnt(int x)
{
	int s=0;
	while(x>0)
	{
		s+=cnt[x];
		x-=lowbit(x);
	}
	return s;
}

int addsum(int x,LL v)
{
	while(x<maxn)
	{
		sum[x]+=v;
		x+=lowbit(x);
	}
	return 0;
}

LL getsum(int x)
{
	LL s=0;
	while(x>0)
	{
		s+=sum[x];
		x-=lowbit(x);
	}
	return s;
}

int lowbit(int x)
{
	return x&(-x);
}

int cmp(II a,II b)
{
	return a.v<b.v;
}
