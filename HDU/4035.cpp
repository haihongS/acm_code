/* ***********************************************
Author        :shootPlane
Created Time  :2016/5/22 19:45:36
File Name     :D:\sherlock\main.cpp
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
const int maxn=2e4+9;
const int inf=1e9+9;
const double eps=1e-9;

int n;
double k[maxn],e[maxn];
double a[maxn],b[maxn],c[maxn];
vector<int> aha[maxn];
int flag[maxn];

int dfs(int node,int f);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
	scanf("%d",&t);
	int cass=1;
	while(t--)
	{
		for(int i=0;i<maxn;i++) aha[i].clear();

		scanf("%d",&n);
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			aha[x].push_back(y);
			aha[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
		{
			double tk,te;
			scanf("%lf%lf",&tk,&te);
			k[i]=tk/100,e[i]=te/100;
		}

		printf("Case %d: ",cass++);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(flag,0,sizeof(flag));

		dfs(1,1);
		if(fabs(1-a[1])<eps)
		{
			printf("impossible\n");continue;
		}
		double ans=c[1]/(1-a[1]);
		printf("%.6lf\n",ans);
	}
    return 0;
}

int dfs(int node,int f)
{
	int len=aha[node].size();

	double tmp1=0,tmp2=0,tmp3=0;
	double m=(double)len;
	for(int i=0;i<len;i++)
	{
		if(aha[node][i]==f) continue;
		int next=aha[node][i];
		int tt=dfs(next,node);
		if(tt) return 1;
		tmp1+=a[next];
		tmp2+=b[next];
		tmp3+=c[next];
	}
	double pp=(1-k[node]-e[node])/m;
	if(fabs(1-pp*tmp2)<eps) return 1;
	a[node]=(k[node]+pp*tmp1)/(1-pp*tmp2);
	b[node]=pp/(1-pp*tmp2);
	c[node]=(pp*tmp3+pp*m)/(1-pp*tmp2);
	return 0;
}
