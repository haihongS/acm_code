#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long ll;
const int maxn=2e5+9;


int main()
{
	int t[10];
	int ans=0;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&t[i]);
		ans+=t[i];
	}
	for(int i=0;i<5;i++)
	{
		int tmp=t[i];
		int cnt=0;
		for(int j=0;j<5;j++)
			if(t[j]==tmp)
				cnt++;
		if(cnt<2)
			continue;
		int sum=0;
		for(int j=0;j<5;j++)
			sum+=t[j];
		if(cnt==2)
			sum-=cnt*tmp;
		else if(cnt>2)
			sum-=3*tmp;
		ans=min(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}
