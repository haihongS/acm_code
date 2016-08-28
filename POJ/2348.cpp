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
const double inf=1e99;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b) && a+b)
	{
		if(a>b) swap(a,b);
		int flag=1;
		while(1)
		{
			if(a>b) swap(a,b);
			if(b%a==0) break;
			if(b-a>a) break;
			b-=a;
			flag=!flag;
		}
		if(flag==1)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}

