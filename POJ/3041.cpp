#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn=1000+9;
const int inf=2e9+9;

struct edge
{
	int to,cap,rev;
};

vector<edge> G[maxn];
int level[maxn];
int iter[maxn];

void add_edge(int from,int to,int cap);
void bfs(int s);
int dfs(int v,int t,int f);
int max_flow(int s,int t);

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		for(int i=0;i<maxn;i++)
			G[i].clear();
		while(k--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u+1,v+1+n,1);
		}
		for(int i=1;i<=n;i++)
		{
			add_edge(0,i+1,1);
			add_edge(i+1+n,1,1);
		}
		printf("%d\n",max_flow(0,1));

	}
	return 0;
}

int max_flow(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s);
		if(level[t]<0)
			return flow;
			memset(iter,0,sizeof(iter));
			int f;
			while((f=dfs(s,t,inf))>0)
				flow+=f;
	}
}


int dfs(int v,int t,int f)
{
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to])
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

void bfs(int s)
{
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++)
		{
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0)
			{
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}



void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}

