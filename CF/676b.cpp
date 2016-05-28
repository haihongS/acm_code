/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月28日 星期六 16时55分18秒
File Name     :476b.cpp
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
const int inf=1e9+9;

double dp[maxn][maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t;
	while(~scanf("%d%d",&n,&t))
	{
		memset(dp,0,sizeof(dp));
		int ans=0;
		dp[1][1]=(double)t;
		if(t>=1)
		{
			ans++;
			dp[1][1]-=1;
		}
		else dp[1][1]=0;

		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				dp[i][j]+=dp[i-1][j-1]+dp[i-1][j];
				dp[i][j]/=2;
				if(dp[i][j]>=1)
				{
					ans++;
					dp[i][j]-=1;
				}
				else dp[i][j]=0;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
