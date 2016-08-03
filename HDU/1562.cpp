#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>


using namespace std;
typedef long long ll;
const int maxn=2e5+9;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int flag=0;
		for(int i=1000;i<=9999;i++)
		{
			if(i%a==0 && (i+1)%b==0 && (i+2)%c==0)
			{
				flag=i;break;
			}
		}
		if(flag==0)
			printf("Impossible\n");
		else
			printf("%d\n",flag);
	}
	return 0;
}
