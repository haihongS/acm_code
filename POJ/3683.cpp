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
const int maxn=5e3+9;

int s[maxn],t[maxn],d[maxn];
vector<int> G[maxn];
vector<int> rG[maxn];
int used[maxn],cnt,flag[maxn],topo[maxn];

int change(char time[]);
int dfs(int node,int fa);
int rdfs(int node,int fa,int k);
int scc(int n);
int add_edge(int u,int v);
int judge(int a,int b,int c,int d);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		//init
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			rG[i].clear();
		}

		for(int i=0;i<n;i++)
		{
			char duru[20];
			scanf("%s",duru);
			s[i]=change(duru);
			scanf("%s",duru);
			t[i]=change(duru);
			scanf("%d",&d[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(judge(s[i],s[i]+d[i],s[j],s[j]+d[j]))
				{
					add_edge(i,j+n); add_edge(j,i+n);
				}
				if(judge(s[i],s[i]+d[i],t[j]-d[j],t[j]))
				{
					add_edge(i,j);
					add_edge(j+n,i+n);
				}
				if(judge(t[i]-d[i],t[i],s[j],s[j]+d[j]))
				{
					add_edge(i+n,j+n);
					add_edge(j,i);
				}
				if(judge(t[i]-d[i],t[i],t[j]-d[j],t[j]))
				{
					add_edge(i+n,j);
					add_edge(j+n,i);
				}
			}
		}
		int go=scc(2*n);
		int bb=0;
		for(int i=0;i<n;i++)
		{
			if(topo[i]==topo[i+n])
			{
				printf("NO\n");
				bb=-1;
				break;
			}
		}
		if(bb==-1) continue;
		printf("YES\n");
		for(int i=0;i<n;i++)
		{
			if(topo[i]>topo[i+n])
				printf("%02d:%02d %02d:%02d\n",s[i]/60,s[i]%60,(s[i]+d[i])/60,(s[i]+d[i])%60);
			else
				printf("%02d:%02d %02d:%02d\n",(t[i]-d[i])/60,(t[i]-d[i])%60,t[i]/60,t[i]%60);
		}
	}
	return 0;
}

int judge(int a,int b,int c,int d)
{
	if(c>=b || a>=d) return 0;
	return 1;
}

int add_edge(int u,int v)
{
	//printf("**%d %d\n",u,v);
	G[u].push_back(v);
	rG[v].push_back(u);
	return 0;
}


int scc(int n)
{
	memset(used,0,sizeof(used));
	cnt=0;
	for(int i=0;i<n;i++)
		if(used[i]==0) dfs(i,i);
	memset(used,0,sizeof(used));
	int bb=0;
	for(int i=cnt-1;i>=0;i--)
	{
		if(used[flag[i]]==0)
			rdfs(flag[i],flag[i],bb++);
	}
	return bb;
}

int rdfs(int node,int fa,int k)
{
	int len=rG[node].size();
	used[node]=1;
	topo[node]=k;
	for(int i=0;i<len;i++)
	{
		int nx=rG[node][i];
		if(nx==fa || used[nx]==1) continue;
		rdfs(nx,node,k);
	}
	return 0;
}

int dfs(int node,int fa)
{
	int len=G[node].size();
	used[node]=1;
	for(int i=0;i<len;i++)
	{
		int nx=G[node][i];
		if(nx==fa || used[nx]==1) continue;
		dfs(nx,node);
	}
	flag[cnt++]=node;
	return 0;
}

int change(char time[])
{
	int len=strlen(time);
	int hh,mm;
	hh=mm=0;
	int f=0;
	for(int i=0;i<len;i++)
	{
		if(time[i]==':')
		{
			f=1;continue;
		}
		int tmp=time[i]-'0';
		if(f==0)
			hh=hh*10+tmp;
		else
			mm=mm*10+tmp;
	}
	return hh*60+mm;
}
