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
	int t,s,x;
	while(~scanf("%d%d%d",&t,&s,&x))
	{
		if(x<t)
		{
			printf("NO\n");
			continue;
		}
		if(x==0 && t!=0)
		{
			printf("NO\n");continue;
		}
		if(x==t)
		{
			printf("YES\n");continue;
		}
		int t1=x-t;
		if(t1!=0 && t1%s==0)
		{
			printf("YES\n");continue;
		}
		int t2=t1-1;
		if(t2!=0 && t2%s==0)
		{
			printf("YES\n");continue;
		}
		printf("NO\n");
	}
	return 0;
}
