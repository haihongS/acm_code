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
const int maxn=5e4+9;
const double eps=1e-9;
const double inf=1e8;

char mapp[2000][10];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%s",mapp[i]);
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(mapp[i][0]=='O' && mapp[i][1]=='O')
			{
				flag=1;
				mapp[i][0]='+',mapp[i][1]='+';
				break;
			}
			if(mapp[i][3]=='O' && mapp[i][4]=='O')
			{
				flag=1;
				mapp[i][3]=mapp[i][4]='+';
				break;
			}
		}
		if(flag==0)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				printf("%s\n",mapp[i]);
			}
		}
	}
	return 0;
}
