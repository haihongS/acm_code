/* ***********************************************
Author        :shootPlane
Created Time  :2016年04月18日 星期一 18时31分54秒
File Name     :2886.cpp
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
typedef long long ll;
const int maxn=5e5+9;
const int inf=1e9+9;

struct II
{
	int dir;
	char name[20];
}duru[maxn];

int n,k;
int num[maxn],flag[maxn];
int c[maxn];

int deal();
int lowbit(int x);
void add(int x,int v);
int query(int x);
int bit1(int lt,int rt,int v);
int bit2(int lt,int rt,int v);
int bit3(int lt,int rt,int v);
int bit4(int lt,int rt,int v);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	memset(num,0,sizeof(num));
	memset(flag,0,sizeof(flag));
	deal();
	int last=-1;
	for(int i=1;i<maxn;i++)
	{
		if(num[i]>last)
		{
			flag[i]=num[i];last=num[i];
		}
		else
			flag[i]=flag[i-1];
	}

    while(~scanf("%d%d",&n,&k))
	{
		int loca,tmp=-1;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]>tmp)
			{
				tmp=flag[i];loca=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s%d",duru[i].name,&duru[i].dir);
			add(i,1);
		}
		int dd=k;
		for(int i=1;i<loca;i++)
		{
			int go=duru[dd].dir;
			add(dd,-1);
			if(go>0)
			{
				go=go%(n-i);
				int t1=query(n),t2=query(dd);
				if(t1-t2>=go)
				{
					dd=bit1(dd,n,go);continue;
				}
				else
				{
					go-=(t1-t2);
					dd=bit2(1,dd,go);continue;
				}
			}
			else
			{
				go=go%(n-i);
				go%=n;
				int t1=query(dd);
				if(t1>=go)
				{
					dd=bit3(1,dd,go);continue;
				}
				else
				{
					go-=t1;
					dd=bit4(dd,n,go);continue;
				}
			}
		}
		printf("%s %d\n",duru[dd].name,tmp);


	}
    return 0;
}

int bit4(int lt,int rt,int v)
{
	int low=lt,up=rt,mid;
	int ans=rt;
	int tmp1=query(rt);
	while(low<=up)
	{
		int mid=low+(up-low)/2;
		int tmp2=query(mid);
		if(tmp1-tmp2<=v)
		{
			ans=min(ans,mid);
			up=mid-1;
		}
		else
			low=mid+1;
	}
	return ans;
}

int bit3(int lt,int rt,int v)
{
	int low=lt,up=rt,mid;
	int ans=rt;
	while(low<=up)
	{
		int mid=low+(up-low)/2;
		int tmp1=query(mid),tmp2=query(rt);
		if(tmp2-tmp1<=v)
		{
			ans=min(ans,mid);
			up=mid-1;
		}
		else
			low=mid+1;
	}
	return ans;
}

int bit2(int lt,int rt,int v)
{
	int low=lt,up=rt,mid;
	int ans=lt;
	while(low<=up)
	{
		int mid=low+(up-low)/2;
		int tmp1=query(mid);
		if(tmp1<=v)
		{
			ans=max(ans,mid);
			low=mid+1;
		}
		else
			up=mid-1;
	}
	return ans;
}

int bit1(int lt,int rt,int v)
{
	int low=lt,up=rt,mid;
	int ans=lt;
	while(low<=up)
	{
		mid=low+(up-low)/2;
		int tmp1=query(mid),tmp2=query(lt);
		if(tmp1-tmp2>v)
			up=mid-1;
		else
		{
			low=mid+1;
			ans=max(ans,mid);
		}
	}
	return ans;
}

int query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=c[x];x-=lowbit(x);
	}
	return ret;
}

void add(int x,int v)
{
	while(x<maxn)
	{
		c[x]+=v;x+=lowbit(x);
	}
	return ;
}

int deal()
{
	for(int i=1;i<maxn;i++)
		for(int j=i;j<maxn;j+=i)
			num[j]++;
	return 0;
}

int lowbit(int x)
{
	return x&(-x);
}
