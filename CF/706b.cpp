#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

ll num[maxn];

ll sumit(int x);
int lowbit(int x);
int update(int x);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			update(x);
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int x;
			scanf("%d",&x);
			if(x>=maxn)
				x=maxn-1;
			printf("%lld\n",sumit(x));
		}
	}
	return 0;
}

int update(int x)
{
	while(x<maxn)
	{
		num[x]+=1;
		x+=lowbit(x);
	}
	return 0;
}

ll sumit(int x)
{
	ll ans=0;
	while(x)
	{
		ans+=num[x];
		x-=lowbit(x);
	}
	return ans;
}


int lowbit(int x)
{
	return x&(-x);
}
