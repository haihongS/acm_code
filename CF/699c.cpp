#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const int inf=2e9+9;

int num[1000];
int dp[108][5];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			if(num[i]==1 || num[i]==3)
				dp[i][1]=max(dp[i-1][0]+1,dp[i-1][2]+1);
			if(num[i]==2 || num[i]==3)
				dp[i][2]=max(dp[i-1][0]+1,dp[i-1][1]+1);
			for(int j=0;j<3;j++)
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
				ans=max(ans,dp[i][j]);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
