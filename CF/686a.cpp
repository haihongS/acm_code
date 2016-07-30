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


int main()
{
	ll n,x;
	while(~scanf("%lld%lld",&n,&x))
	{
		ll cnt=0,ans=x;
		while(n--)
		{
			char op[10];
			scanf("%s",op);
			int num;
			scanf("%d",&num);
			if(op[0]=='+')
				ans+=num;
			else
			{
				if(ans>=num)
				{
					ans-=num;
				}
				else
					cnt++;
			}
		}
		printf("%lld %lld\n",ans,cnt);
	}
	return 0;
}
