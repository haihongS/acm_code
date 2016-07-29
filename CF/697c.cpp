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

map<ll,ll> aha;

ll cal(ll u,ll v,ll w,ll op);

int main()
{
	int q;
	while(~scanf("%d",&q))
	{
		aha.clear();
		while(q--)
		{
			int op;
			ll u,v,w;
			scanf("%d",&op);
			scanf("%lld%lld",&u,&v);
			if(op==1) scanf("%lld",&w);
			ll ans=cal(u,v,w,op);
			if(op==2)
				printf("%lld\n",ans);
		}
	}
	return 0;
}

ll cal(ll u,ll v,ll w,ll op)
{
	ll ans=0;
	ll x1=u,x2=v;
	while(x1!=x2)
	{
		if(x1>x2) swap(x1,x2);
		if(op==1) aha[x2]+=w;
		ans+=aha[x2];
		x2/=2;
	}
	return ans;
}
