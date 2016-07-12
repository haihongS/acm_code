#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
const int maxn=1500+9;
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
int num[maxn];

int main()
{
	int m,n;
	while(~scanf("%d%d",&m,&n))
	{
		for(int i=0;i<maxn;i++)
			G[i].clear();
		int index=2;
		for(int i=1;i<=m;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			num[i]=index;
			add_edge(0,index,tmp);
			index++;
		}
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			for(int j=0;j<a;j++)
			{
				int tmp;
				scanf("%d",&tmp);
				add_edge(num[tmp],index,inf);
				num[tmp]=index;
			}
			int b;
			scanf("%d",&b);
			add_edge(index,1,b);
			index++;
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
