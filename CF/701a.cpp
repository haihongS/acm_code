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
const int maxn=25;
const int inf=2e9+9;

int num[200];
int f[200];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		int x=sum*2/n;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			if(f[i]==1) continue;
			printf("%d",i);
			for(int j=i+1;j<=n;j++)
			{
				if(f[j]==1) continue;
				if(num[j]+num[i]==x)
				{
					f[j]=1;
					printf(" %d\n",j);
					break;
				}
			}
		}
	}
	return 0;
}
