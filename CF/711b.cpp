#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const double eps=1e-9;
const double inf=1e8;

ll num[maxn][maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int sx,sy;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%lld",&num[i][j]);
				if(num[i][j]==0)
				{
					sx=i,sy=j;
				}
			}
		}
		if(n==1 && num[1][1]==0)
		{
			printf("1\n");continue;
		}
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			if(i==sx) continue;
			ll tmp=0;
			for(int j=1;j<=n;j++)
			{
				tmp+=num[i][j];
			}
			sum=tmp;break;
		}
		ll go=0;
		for(int i=1;i<=n;i++)
		{
			go+=num[i][sy];
		}
		num[sx][sy]=sum-go;
		int flag=1;
		if(num[sx][sy]<=0) flag=-1;
		for(int i=1;i<=n;i++)
		{
			ll t1=0,t2=0;
			for(int j=1;j<=n;j++)
			{
				t1+=num[i][j];
				t2+=num[j][i];
			}
			if(t1!=sum || t2!=sum)
			{
				flag=-1;break;
			}
		}
		ll g1=0,g2=0;
		for(int i=1;i<=n;i++)
		{
			g1+=num[i][i];
			g2+=num[i][n-i+1];
		}
		if(g1!=sum || g2!=sum)
			flag=-1;
		if(flag==-1)
			printf("-1\n");
		else
			printf("%lld\n",num[sx][sy]);

	}
	return 0;
}
