/* ***********************************************
Author        :shootPlane
Created Time  :2016年04月13日 星期三 17时15分23秒
File Name     :2155.cpp
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
const int maxn=1e3+9;
const int inf=1e9+9;

int n,t;
int c[maxn][maxn];

int lowbit(int x);
void add(int x,int y,int tt);
int sum(int x,int y);


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int mm;
	scanf("%d",&mm);
	int qq=0;
	while(mm--)
	{
		if(qq>0) printf("\n");
		qq++;
		scanf("%d%d",&n,&t);
		memset(c,0,sizeof(c));
		while(t--)
		{
			char op[10];
			scanf("%s",op);
			if(op[0]=='Q')
			{
				int x,y;
				scanf("%d%d",&x,&y);
				int ans=sum(x,y);
				printf("%d\n",ans%2);
			}
			else
			{
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				int tmp=x1;
				x1=min(tmp,x2),x2=max(tmp,x2);
				tmp=y1;
				y1=min(tmp,y2),y2=max(tmp,y2);
				add(x1,y1,1),add(x2+1,y1,1),add(x1,y2+1,1),add(x2+1,y2+1,1);
			}
		}
	}
    return 0;
}


int sum(int x,int y)
{
	int ret=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		for(int j=y;j>0;j-=lowbit(j))
		{
			ret+=c[i][j];
		}
	}
	return ret;
}

void add(int x,int y,int tt)
{
	for(int i=x;i<maxn;i+=lowbit(i))
	{
		for(int j=y;j<maxn;j+=lowbit(j))
		{
			c[i][j]+=tt;
		}
	}
	return ;
}

int lowbit(int x)
{
	return x&(-x);
}
