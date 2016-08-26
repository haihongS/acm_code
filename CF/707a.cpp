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
const int maxn=59+9;
const int inf=2e9+9;


int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				char x[100];
				scanf("%s",x);
				if(x[0]=='B' || x[0]=='W' || x[0]=='G')
					continue;
				flag=-1;
			}
		}
		if(flag==1)
			printf("#Black&White\n");
		else
			printf("#Color\n");
	}

	return 0;
}
