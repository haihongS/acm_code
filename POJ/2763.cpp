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
const int maxn=4e5+9;

struct II
{
	int from,to,cost;
	int next;
}num[maxn],G[maxn];

int head[maxn];

int siz[maxn],dep[maxn],fa[maxn],son[maxn],top[maxn];
int id[maxn],rank[maxn];
int tot;

int sum[maxn],add[maxn],val[maxn];

int n,cnt;

int dfs1(int node,int father,int d);
int dfs2(int node,int tp);
int add_edge(int u,int v,int w);
int build(int node,int l,int r);
void push_up(int node);
void push_down(int node,int l,int r);
int query(int node,int l,int r,int L,int R);
int update(int node,int l,int r,int L,int R,int v);
int deal(int u,int v);


int main()
{
	int q,s;
	while(~scanf("%d%d%d",&n,&q,&s))
	{
		for(int i=0;i<maxn;i++)
		{
			head[i]=-1;
			val[i]=0;
		}
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			num[i].from=u,num[i].to=v,num[i].cost=w;
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		tot=0;
		dfs1(1,1,0);
		dfs2(1,1);
		for(int i=1;i<n;i++)
		{
			int u=num[i].from,v=num[i].to;
			if(dep[u]<dep[v])
				swap(num[i].from,num[i].to);
			val[id[num[i].from]]=num[i].cost;
		}
		build(0,1,tot);
		while(q--)
		{
			int op;
			scanf("%d",&op);
			if(op==0)
			{
				int u;
				scanf("%d",&u);
				int ans=deal(s,u);
				printf("%d\n",ans);
				s=u;
			}
			else
			{
				int u,w;
				scanf("%d%d",&u,&w);
				int go=num[u].from;
				go=id[go];
				int tmp=query(0,1,tot,go,go);
				update(0,1,tot,go,go,w-tmp);
			}
		}
	}

	return 0;
}

int deal(int u,int v)
{
	int tp1=top[u],tp2=top[v];
	int ans=0;
	while(tp1!=tp2)
	{
		if(dep[tp1]<dep[tp2])
		{
			swap(u,v);
			swap(tp1,tp2);
		}
		ans+=query(0,1,tot,id[tp1],id[u]);
		u=fa[tp1];
		tp1=top[u];
	}
	if(u==v) return ans;
	if(dep[u]<dep[v])
		swap(u,v);
	ans+=query(0,1,tot,id[son[v]],id[u]);
	//printf("**%d %d\n",id[son[v]],id[u]);
	return ans;
}

int update(int node,int l,int r,int L,int R,int v)
{
	if(L<=l && r<=R)
	{
		add[node]+=v;
		sum[node]+=(r-l+1)*v;
		return 0;
	}
	if(r<L || l>R) return 0;
	push_down(node,l,r);
	int mid=l+(r-l)/2;
	update(2*node+1,l,mid,L,R,v);
	update(2*node+2,mid+1,r,L,R,v);
	push_up(node);
	return 0;
}

int query(int node,int l,int r,int L,int R)
{
	if(L<=l && r<=R)
		return sum[node];
	if(r<L|| l>R) return 0;
	push_down(node,l,r);
	int mid=l+(r-l)/2;
	int ans=0;
	ans+=query(2*node+1,l,mid,L,R);
	ans+=query(2*node+2,mid+1,r,L,R);
	return ans;
}

int build(int node,int l,int r)
{
	if(l==r)
	{
		sum[node]=val[l];
		add[node]=0;
		return 0;
	}
	int mid=l+(r-l)/2;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	push_up(node);
	return 0;
}

void push_down(int node,int l,int r)
{
	if(add[node]!=0)
	{
		int mid=l+(r-l)/2;
		add[2*node+1]+=add[node];
		add[2*node+2]+=add[node];
		sum[2*node+1]+=add[node]*(mid-l+1);
		sum[2*node+2]+=add[node]*(r-mid);
		add[node]=0;
	}
}

void push_up(int node)
{
	sum[node]=sum[2*node+1]+sum[2*node+2];
}

int add_edge(int u,int v,int w)
{
	G[cnt].to=v,G[cnt].cost=w,G[cnt].next=head[u];
	head[u]=cnt++;
	return 0;
}


int dfs2(int node,int tp)
{
	top[node]=tp;
	id[node]=++tot;
	rank[id[node]]=node;
	if(son[node]==-1) return 0;
	dfs2(son[node],tp);

	for(int i=head[node];i!=-1;i=G[i].next)
	{
		int nx=G[i].to;
		if(nx!=fa[node] && nx!=son[node])
		{
			dfs2(nx,nx);
		}
	}
	return 0;
}

int dfs1(int node,int father,int d)
{
	fa[node]=father;
	dep[node]=d;
	siz[node]=1;
	son[node]=-1;
	for(int i=head[node];i!=-1;i=G[i].next)
	{
		int nx=G[i].to;
		if(nx==father) continue;
		dfs1(nx,node,d+1);
		siz[node]+=siz[nx];
		if(son[node]==-1 || siz[son[node]]<siz[nx])
			son[node]=nx;
	}
	return 0;
}

