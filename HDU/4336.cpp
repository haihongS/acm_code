/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月27日 星期五 19时58分06秒
File Name     :4336.cpp
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
const int maxn=21;
const int inf=1e9+9;

double p[maxn];
double dp[1<<maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(~scanf("%d",&n))
	{
		double p0=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&p[i]);
			p0+=p[i];
		}
		p0=1-p0;

		memset(dp,0,sizeof(dp));
		for(int i=(1<<n)-2;i>=0;i--)
		{
			double tmp1=0,tmp2=0;
			for(int j=0;j<n;j++)
			{
				if(i==(i|(1<<j)))
				{
					tmp1+=p[j];
				}
				else
					tmp2+=p[j]*dp[i|(1<<j)];
			}
			dp[i]=1.0*(1+tmp2)/(1-tmp1-p0);
		}
		printf("%.5lf\n",dp[0]);

		
	}
    return 0;
}
