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
const int maxn=1000+9;
const int inf=2e9+9;

int n,m;
char mapp[maxn][maxn];
int fx[maxn],fy[maxn];

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(fx,0,sizeof(fx));
		memset(fy,0,sizeof(fy));
		for(int i=0;i<n;i++)
			scanf("%s",mapp[i]);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mapp[i][j]=='*')
				{
					sum++;
					fx[i]+=1,fy[j]+=1;
				}
			}
		}
		int x,y;
		x=y=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int tmp=fx[i]+fy[j];
				if(mapp[i][j]=='*')
					tmp--;
				if(tmp==sum)
				{
					x=i+1,y=j+1;
				}
			}
		}
		if(x==-1)
			printf("NO\n");
		else
			printf("YES\n%d %d\n",x,y);
	}
	return 0;
}
