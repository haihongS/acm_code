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
	int n;
	while(scanf("%d",&n) && n)
	{
		if(n<=2)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}
