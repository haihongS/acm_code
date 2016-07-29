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
const int maxn=2e5+9;
const int inf=1000000;

int fa[maxn],son[maxn],deep[maxn];
vector<int> G[maxn];

int dfs(int node,int from,int len);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
		}
		fa[1]=1;
		for(int i=2;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			fa[i]=x;
			G[x].push_back(i);
		}
		dfs(1,1,1);
		for(int i=1;i<=n;i++)
		{
			if(i==1) printf("1.0");
			else
			{
				double tmp=1.0*(deep[i]+n-son[i])/2;
				printf(" %.9f",tmp);
			}
		}
		printf("\n");

	}
	return 0;
}


int dfs(int node,int from,int len)
{
	int cnt=0;
	for(int i=0;i<G[node].size();i++)
	{
		int tmp=G[node][i];
		if(tmp==from) continue;
		cnt+=dfs(tmp,node,len+1);
	}
	son[node]=cnt,deep[node]=len;
	return cnt+1;
}
