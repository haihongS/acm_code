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
	int n;
	while(scanf("%d",&n) && n)
	{
		int tmp=n*n;
		if(tmp&1)
			printf("ailyanlu\n");
		else
			printf("8600\n");
	}
	return 0;
}
