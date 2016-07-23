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
const int inf=2e9+9;

ll row[maxn],col[maxn];
int fr[maxn],fc[maxn];

ll sum(int x,int f);
int lowbit(int x);
int update(int x,ll v,int f);

int main()
{
	ll n,m;
	while(~scanf("%lld%lld",&n,&m))
	{
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(fr,0,sizeof(fr));
		memset(fc,0,sizeof(fc));
		int ss=0;
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(fr[x]==0)
			{
				fr[x]=1;
				update(x,1,1);
			}
			if(fc[y]==0)
			{
				fc[y]=1;
				update(y,1,2);
			}

			ll rr=sum(n,1);
			ll cc=sum(n,2);
			rr=n-rr,cc=n-cc;
			if(ss==0)
			{
				printf("%lld",rr*cc);ss=1;
			}
			else
				printf(" %lld",rr*cc);
		}
		printf("\n");
	}
	return 0;
}
int update(int x,ll v,int f)
{
	while(x<maxn)
	{
		if(f==1)
			row[x]+=v;
		else if(f==2)
			col[x]+=v;
		
		x+=lowbit(x);
	}
	return 0;
}

ll sum(int x,int f)
{
	ll ans=0;

	while(x>0)
	{
		if(f==1)
			ans+=row[x];
		else if(f==2)
			ans+=col[x];
		x-=lowbit(x);
	}
	return ans;
}

int lowbit(int x)
{
	return x&(-x);
}
