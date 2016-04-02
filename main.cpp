/* ***********************************************
Author        :shootPlane
Created Time  :2016年04月02日 星期六 10时40分41秒
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
typedef long long ll;
const int maxn=2e3+9;
const ll inf=3e12+9;

int t[maxn];
ll c[maxn];
ll dp[2*maxn][2*maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++) scanf("%d%lld",&t[i],&c[i]);
		for(int i=0;i<2*maxn;i++)
			for(int j=0;j<2*maxn;j++)
				dp[i][j]=inf;
		dp[0][n]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=2*n;j++)
			{
				if(j-t[i]<0)
					dp[i][j]=dp[i-1][j+1];
				else
					dp[i][j]=min(dp[i-1][j+1],dp[i-1][j-t[i]]+c[i]);
			}
		}
		ll ans=inf;
		for(int i=n;i<=n+n;i++)
			ans=min(ans,dp[n][i]);
		printf("%lld\n",ans);

	}
    return 0;
}
