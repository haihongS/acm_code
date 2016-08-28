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
const int maxn=2e2+9;

int sg[maxn][maxn];

int get(int w,int h);

int main()
{
	get(maxn-1,maxn-1);
	int w,h;
	while(~scanf("%d%d",&w,&h))
	{
		if(sg[w][h]==0)
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}

int get(int w,int h)
{
	memset(sg,0,sizeof(sg));
	for(int i=1;i<maxn;i++) sg[i][1]=sg[1][i]=1;
	for(int p=2;p<w;p++)
	{
		for(int q=2;q<h;q++)
		{
			int flag[maxn];
			memset(flag,0,sizeof(flag));
			for(int i=2;p-i>=2;i++)
				flag[sg[p-i][q]^sg[i][q]]=1;
			for(int i=2;q-i>=2;i++)
				flag[sg[p][q-i]^sg[p][i]]=1;

			for(int i=0;i<maxn;i++)
			{
				if(flag[i]==0)
				{
					sg[p][q]=i;
					break;
				}
			}
		}
	}
	return 0;
}

