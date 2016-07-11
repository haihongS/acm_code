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
const int maxn=900+9;
const int inf=2e9+9;


struct edge
{
	int to,cap,rev;
};

vector<edge> G[maxn];
int level[maxn];
int iter[maxn];
map<string,int> aha;
char recep[109][30];
char equip[109][30];

void add_edge(int from,int to,int cap);
void bfs(int s);
int dfs(int v,int t,int f);
int max_flow(int s,int t);

int main()
{
	for(int i=0;i<maxn;i++)
		G[i].clear();
	aha.clear();

	int n,m,k;
	scanf("%d",&n);
	int ff=2;
	for(int i=0;i<n;i++)
	{
		scanf("%s",recep[i]);
		aha[recep[i]]=ff;
		add_edge(ff,1,1);
		ff+=1;
	}
	scanf("%d",&m);
	int index=401;
	for(int i=0;i<m;i++)
	{
		scanf("%s",equip[i]);
		scanf("%s",equip[i]);
		if(aha.find(equip[i])!=aha.end())
		{
			add_edge(index,aha[equip[i]],1);
		}
		else
		{
			aha[equip[i]]=ff;
			add_edge(index,ff,1);
			ff+=1;
		}
		add_edge(0,index,1);
		index++;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		char u[30],v[30];
		scanf("%s %s",u,v);
		if(aha.find(u)==aha.end())
			aha[u]=ff++;
		if(aha.find(v)==aha.end())
			aha[v]=ff++;
		int u1,v1;
		u1=aha[u],v1=aha[v];
		add_edge(u1,v1,10000);
	}
	printf("%d\n",m-max_flow(0,1));


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
