#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long ll;
const int maxn=2e5+9;

int num[200];

int main()
{
	int n,a;
	while(~scanf("%d%d",&n,&a))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		int lt,rt;
		lt=rt=a;
		int ans=0;
		while(lt>=1 || rt<=n)
		{
			if(lt==rt && num[lt]==1)
				ans+=1;
			else if(1<=lt && rt<=n)
			{
				if(num[lt]==1 && num[rt]==1)
					ans+=2;
			}
			else if(1<=lt && num[lt]==1)
				ans++;
			else if(rt<=n && num[rt]==1)
				ans++;
			lt--,rt++;
		}
		printf("%d\n",ans);
	}

	return 0;
}
