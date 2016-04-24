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
int bit(int lt,int rt,int v);

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
		int loca,stmp=-1;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]>stmp)
			{
				stmp=flag[i];loca=i;
			}
		}
		memset(c,0,sizeof(c));
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
				int tmp=go%(n-i);
				if(tmp==0) tmp=n-i;
				int next;
				int t1=query(n),t2=query(dd);
				if(t1-t2>=tmp)
                    next=bit(dd,n,tmp+t2);
                else
                    next=bit(1,dd,tmp-(t1-t2));
				dd=next;continue;
			}
			else
			{
				int tmp;
			    tmp=go%(n-i);
			    if(tmp<0) tmp=-tmp;
			    if(tmp==0) tmp=n-i;
                int next;
                int t1=query(dd);
                if(t1>=tmp)
                    next=bit(1,dd,t1-tmp+1);
                else
                    next=bit(dd+1,n,query(n)-(tmp-t1)+1);
				dd=next;continue;
			}
		}
		printf("%s %d\n",duru[dd].name,stmp);
	}
    return 0;
}

int bit(int lt,int rt,int v)
{
	int low=lt,up=rt,mid,ans=rt;
	while(low<=up)
	{
		mid=low+(up-low)/2;
		if(query(mid)>=v)
		{
			ans=min(ans,mid);
			up=mid-1;
		}
		else
			low=mid+1;
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

