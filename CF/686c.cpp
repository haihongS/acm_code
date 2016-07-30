#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=1000000;
typedef pair<int,int> P;

int num[10];
map<P,int> aha;

int deal(int lt,int rt);

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		n--,m--;
		aha.clear();
		for(int i=0;i<7;i++)
			num[i]=i;
		int ans=0;
		int nlen,mlen;
		nlen=mlen=0;
		int tn=n,tm=m;
		while(tn>0)
		{
			nlen++;
			tn/=7;
		}
		while(tm>0)
		{
			mlen++;
			tm/=7;
		}
		if(nlen==0) nlen=1;
		if(mlen==0) mlen=1;
		if(nlen+mlen>7)
		{
			printf("0\n");
			continue;
		}
		do
		{
			int t1=deal(0,nlen-1);
			int t2=deal(nlen,nlen+mlen-1);
			if(t1==0 && t2==0) continue;
			if(t1<=n && t2<=m)
			{
				if(aha[P(t1,t2)]==1) continue;
				aha[P(t1,t2)]=1;
				ans++;
			}
		}while(next_permutation(num,num+7));
		printf("%d\n",ans);
	}
	return 0;
}

int deal(int lt,int rt)
{
	int ans=0;
	int loca=1;
	for(int i=rt;i>=lt;i--)
	{
		ans+=num[i]*loca;
		loca*=7;
	}
	return ans;
}
