#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

char num[maxn];
map<char,int> aha;
int bi[maxn],flag[maxn];

int sum(int x);
int update(int x,int v);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		scanf("%s",num);
		aha.clear();
		memset(bi,0,sizeof(bi));
		memset(flag,0,sizeof(flag));
		int index=1;
		int len=strlen(num);
		for(int i=0;i<len;i++)
		{
			if(aha[num[i]]==0)
				aha[num[i]]=index++;
		}
		int lt=0,rt=0;
		update(aha[num[0]],1);
		flag[aha[num[0]]]=1;
		int ans=inf;
		while(lt<=rt && rt<len)
		{
			int vv=sum(index-1);
			if(vv==index-1)
			{
				ans=min(ans,rt-lt+1);
				if(flag[aha[num[lt]]]==1)
					update(aha[num[lt]],-1);
				flag[aha[num[lt]]]--;
				lt++;
			}
			else if(vv>index-1)
			{
				if(flag[aha[num[lt]]]==1)
					update(aha[num[lt]],-1);
				flag[aha[num[lt]]]--;
				lt++;
			}
			else if(vv<index-1)
			{
				rt++;
				if(rt>=len) break;
				if(flag[aha[num[rt]]]==0)
					update(aha[num[rt]],1);
				flag[aha[num[rt]]]++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

int update(int x,int v)
{
	while(x<maxn)
	{
		bi[x]+=v;
		x+=x&(-x);
	}
	return 0;
}


int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=bi[x];
		x-=x&(-x);
	}
	return ans;
}
