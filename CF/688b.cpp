#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

int main()
{
	char n[maxn];
	while(~scanf("%s",n))
	{
		int len=strlen(n);
		for(int i=0;i<len;i++)
			printf("%c",n[i]);
		for(int i=len-1;i>=0;i--)
			printf("%c",n[i]);
		printf("\n");
	}
	return 0;
}
