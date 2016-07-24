#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=2e4+9;
const int inf=2e9+9;

struct edge
{
	int to,cap,rev;
};

vector<edge> G[maxn];
int level[maxn],iter[maxn];

void add_edge(int from,int to,int cap);
void bfs(int s);
int dfs(int v,int t,int f);
int max_flow(int s,int t);

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<maxn;i++)
			G[i].clear();
		for(int i=1;i<=n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add_edge(i,n+1,a);
			add_edge(0,i,b);
		}
		while(m--)
		{
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			add_edge(a,b,w);
			add_edge(b,a,w);
		}
		printf("%d\n",max_flow(0,n+1));
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

