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


int num[maxn];
char move[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		scanf("%s",move);
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		int ans=inf;
		if(n==2)
		{
			if(move[0]=='R' && move[1]=='L')
				ans=(num[1]-num[0])/2;
		}
		for(int i=1;i<n-1;i++)
		{
			int tmp=inf;
			if(move[i-1]=='R' && move[i]=='L')
				tmp=(num[i]-num[i-1])/2;
			if(move[i]=='R' && move[i+1]=='L')
				tmp=(num[i+1]-num[i])/2;
			ans=min(ans,tmp);
		}
		if(ans==inf)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
