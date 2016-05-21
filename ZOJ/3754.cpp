/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月21日 星期六 20时48分22秒
File Name     :3754.cpp
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
const int maxn=6e2+9;
const int inf=1e9+9;

double p[20];
double a[maxn],b[maxn];
double dp[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k1,k2,k3,ta,tb,tc;
		scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&ta,&tb,&tc);
		memset(p,0,sizeof(p));
		for(int i=1;i<=k1;i++)
			for(int j=1;j<=k2;j++)
				for(int k=1;k<=k3;k++)
					p[i+j+k]+=1.0/(k1*k2*k3);
		p[0]=1.0/(k1*k2*k3);
		p[ta+tb+tc]-=p[0];

		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=n;i>=0;i--)
		{
			for(int j=3;j<=k1+k2+k3;j++)
			{
				b[i]+=p[j]*b[i+j];
			}
			b[i]+=1;
		}
		for(int i=n;i>=0;i--)
		{
			for(int j=3;j<=k1+k2+k3;j++)
				a[i]+=p[j]*a[i+j];
			a[i]+=p[0];
		}
		memset(dp,0,sizeof(dp));
		dp[0]=b[0]/(1-a[0]);
		printf("%.10lf\n",dp[0]);

	}
	return 0;
}
