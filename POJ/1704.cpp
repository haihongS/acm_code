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

int num[maxn];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		int ans=0;
		if(n&1)
		{
			ans^=num[0]-1;
			for(int i=1;i<n;i+=2)
			{
				ans^=num[i+1]-num[i]-1;
			}
		}
		else
		{
			for(int i=0;i<n;i+=2)
			{
				ans^=num[i+1]-num[i]-1;
			}
		}
		if(ans==0)
			printf("Bob will win\n");
		else
			printf("Georgia will win\n");

	}
}

