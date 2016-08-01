#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=3e5+9;
const int inf=2e9+9;
const ll mod=1000000007;

string ans;

int main()
{
	ans="";
	for(int i=1;i<=9;i++)
	{
		ans+=(char)(i+'0');
	}
	for(int i=10;i<100;i++)
	{
		int t1=i/10,t2=i%10;
		ans+=(char)(t1+'0');
		ans+=(char)(t2+'0');
	}
	for(int i=100;i<500;i++)
	{
		int t1=i/100,t3=i%10;
		int t2=i-t1*100;t2/=10;
		ans+=(char)(t1+'0');
		ans+=(char)(t2+'0');
		ans+=(char)(t3+'0');
	}
	int n;
	while(~scanf("%d",&n))
	{
		n--;
		cout<<ans[n]<<endl;
	}
	return 0;
}
