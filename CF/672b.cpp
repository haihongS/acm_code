#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=3e5+9;
const int inf=2e9+9;
const ll mod=1000000007;

char num[maxn];
int flag[30];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		scanf("%s",num);
		memset(flag,0,sizeof(flag));
		if(n>26)
		{
			printf("-1\n");continue;
		}
		for(int i=0;i<n;i++)
		{
			flag[num[i]-'a']++;
		}
		int ans=0;
		for(int i=0;i<26;i++)
		{
			if(flag[i]>1)
				ans+=flag[i]-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
