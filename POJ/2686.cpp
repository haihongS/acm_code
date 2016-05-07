/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月07日 星期六 17时03分32秒
File Name     :2686.cpp
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
const int maxn=50+9;
const int inf=1e9+9;

int n,m,p,a,b;
int t[maxn];
double G[maxn][maxn];
double dp[1<<9][maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b) && n+m+p+a+b)
	{
		for(int i=0;i<n;i++) scanf("%d",&t[i]);
		for(int i=0;i<maxn;i++)
			for(int j=0;j<maxn;j++)
				G[i][j]=inf;
		for(int i=0;i<p;i++)
		{
			int x,y;
			double z;
			scanf("%d%d%lf",&x,&y,&z);
			G[x][y]=G[y][x]=z;
		}
		for(int i=0;i<(1<<9);i++)
			for(int j=0;j<maxn;j++)
				dp[i][j]=inf;
	    double ans=inf;	
		dp[(1<<n)-1][a]=0;
		for(int i=(1<<n)-1;i>=0;i--)
		{
			ans=min(ans,dp[i][b]);
			for(int j=1;j<=m;j++)
			{
				for(int k=0;k<n;k++)
	     		{
					//if((i>>k)&1)
					if(i&(1<<k))
					{
						for(int v=1;v<=m;v++)
						{
							if(G[j][v]!=inf)
							{
								dp[i&(~(1<<k))][v]=min(dp[i&(~(1<<k))][v],dp[i][j]+1.0*G[j][v]/t[k]);
							}
						}
					}
				}
			}
		}
		if(ans==inf)
			printf("Impossible\n");
		else
			printf("%.4lf\n",ans);
	}
    return 0;
}
