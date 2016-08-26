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
const int maxn=1e5+9;
const int inf=2e9+9;

struct edge
{
	int to,cost;
};

vector<edge> G[maxn];
int add_edge(int u,int v,int w);
int num[maxn],flag[maxn];

int main()
{
	int n,m,q;
	while(~scanf("%d%d%d",&n,&m,&q))
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
		}
		if(q==0)
		{
			printf("-1\n");continue;
		}
		memset(flag,0,sizeof(flag));
		for(int i=0;i<q;i++)
			scanf("%d",&num[i]),flag[num[i]]=1;
		int ans=-1;
		for(int i=0;i<q;i++)
		{
			int len=G[num[i]].size();
			for(int j=0;j<len;j++)
			{
				edge nx=G[num[i]][j];
				if(flag[nx.to]==1) continue;
				if(ans==-1)
					ans=nx.cost;
				else
					ans=min(ans,nx.cost);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

int add_edge(int u,int v,int w)
{
	edge now;
	now.to=v,now.cost=w;
	G[u].push_back(now);
	now.to=u;
	G[v].push_back(now);
	return 0;
}
