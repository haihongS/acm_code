#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=2e2+9;
const int inf=2e9+9;

int n,np,nc,m;

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
	while(~scanf("%d%d%d%d",&n,&np,&nc,&m))
	{
		for(int i=0;i<maxn;i++)
			G[i].clear();
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			u=v=w=0;
			char tt[20];
			scanf("%s",tt);
			int f=0;
			for(int i=1;i<strlen(tt);i++)
			{
				if(tt[i]==',')
				{
					f=1;continue;
				}
				else if(tt[i]==')')
				{
					f=2;continue;
				}
				if(f==0)
					u=u*10+tt[i]-'0';
				else if(f==1)
					v=v*10+tt[i]-'0';
				else
					w=w*10+tt[i]-'0';
			}
			add_edge(u,v,w);
		}
		for(int i=0;i<np;i++)
		{
			int u,w;
			u=w=0;
			char tt[20];
			scanf("%s",tt);
			int f=0;
			for(int i=1;i<strlen(tt);i++)
			{
				if(tt[i]==')')
				{
					f=1;continue;
				}
				if(f==0)
					u=u*10+tt[i]-'0';
				else if(f==1)
					w=w*10+tt[i]-'0';
			}
			add_edge(150,u,w);
		}
		for(int i=0;i<nc;i++)
		{
			int u,w;
			u=w=0;
			char tt[20];
			scanf("%s",tt);
			int f=0;
			for(int i=1;i<strlen(tt);i++)
			{
				if(tt[i]==')')
				{
					f=1;continue;
				}
				if(f==0)
					u=u*10+tt[i]-'0';
				else if(f==1)
					w=w*10+tt[i]-'0';
			}
			add_edge(u,160,w);
		}
		int ans=max_flow(150,160);
		printf("%d\n",ans);
	}
	return 0;
}

int max_flow(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s);
		if(level[t]<0) return flow;
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

