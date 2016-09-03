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
const int maxn=2e5+9;
const double eps=1e-9;
const ll inf=1e13+9;
const ll mod=1e9+7;

int a[maxn];
int dep[maxn],vis[maxn];
ll ans;
int cnt;

int dfs(int node,int from,int d);
ll quick_pow(ll a,ll b);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=1,cnt=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0) dfs(i,i,1);
		}
		ans*=quick_pow(2LL,(ll)(n-cnt));
		ans%=mod;
		printf("%lld\n",ans);

	}
	return 0;
}

ll quick_pow(ll a,ll b)
{
	ll ans=1,tmp=a%mod;
	while(b)
	{
		if(b&1)
			ans*=tmp;
		ans%=mod;
		tmp*=tmp;
		tmp%=mod;
		b>>=1;
	}
	return ans;
}

int dfs(int node,int from,int d)
{
	dep[node]=d;
	vis[node]=from;
	int nx=a[node];
	if(vis[nx]==0)
		dfs(nx,from,d+1);
	else
	{
		if(vis[nx]==from)
		{
			ll tmp=quick_pow(2LL,(ll)(dep[node]-dep[nx]+1));
			tmp-=2;
			ans=(ans*(tmp+mod))%mod;
			cnt+=dep[node]-dep[nx]+1;
		}
	}
	return 0;
}
