/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月12日 星期四 08时37分19秒
File Name     :1795.cpp
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
const int maxn=1e5+9;
const int inf=1e9+9;

string num[20];
int n;
int dp[1<<17][20],cost[20][20];

int cmp(const string &x,const string &y);
int init();
int dfs();

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
	scanf("%d",&t);
	int cass=1;
	while(t--)
	{
		int n;
		for(int i=0;i<n;i++) cin>>num[i];
		printf("Scenario #%d:\n",cass++);

		sort(num,num+n,cmp);
		int len=unique(num,num+n)-num;
		for(int i=0;i<len;i++)
		{
			dp[1<<i][i]=num[i].length();
		}
		init();

		for(int i=0;i<(1<<len);i++)
		{
			for(int j=0;j<len;j++)
			{
				for(int u=0;u<len;u++)
				{
					dp[i|(1<<u)][u]=min(dp[i|(1<<u)][u],dp[i][j]+cost[i][u]);
				}
			}
		}
		int loca=0,minn=dp[(1<<len)-1][0];
		for(int i=1;i<len;i++)
		{
			if(dp[(1<<len)-1][i]<minn)
			{
				minn=dp[(1<<len)-1][i];
				loca=i;
			}
		}


	}
    return 0;
}

int dfs()
{

}

int init()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			// i>j
			int up=min(num[i].length(),num[j].length());
			int len=num[i].length();
			int tmp=0;
			for(int k=0;k<up;k++)
			{
				int ff=1;
				for(int s=0;s<k;s++)
				{
					if(num[i][len-s]!=num[j][s])
					{
						ff=0;break;
					}
				}
				if(ff)
				{
					tmp=max(tmp,k);
				}
			}
			cost[i][j]=-tmp;
		}
	}
}

int cmp(const string &x,const string &y)
{
	return x<y;
}
