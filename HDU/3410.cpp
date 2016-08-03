#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=5e4+9;

int num[maxn];
int ans1[maxn],ans2[maxn];

int dfs(int pos,int lt,int rt);

int main()
{
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int pri,maxx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]>maxx)
			{
				maxx=num[i];
				pri=i;
			}
		}

		for(int i=0;i<maxn;i++)
		{
			ans1[i]=ans2[i]=0;
		}

		dfs(pri,1,n);
		printf("Case %d:\n",cas++);
		for(int i=1;i<=n;i++)
		{
			printf("%d %d\n",ans1[i],ans2[i]);
		}
	}
	return 0;
}


int dfs(int pos,int lt,int rt)
{
	if(lt==rt)
	{
		ans1[pos]=ans2[pos]=0;return 0;
	}
	int f1=0;
	for(int i=pos-1;i>=lt;i--)
	{
		if(num[i]>num[pos]) break;
		if(f1==0)
			f1=i;
		else if(num[i]>num[f1])
			f1=i;
	}
	if(f1!=0)
		dfs(f1,lt,pos-1);
	
	int f2=0;
	for(int i=pos+1;i<=rt;i++)
	{
		if(num[i]>num[pos]) break;
		if(f2==0)
			f2=i;
		else if(num[i]>num[f2])
			f2=i;
	}
	if(f2!=0)
		dfs(f2,pos+1,rt);
	
	ans1[pos]=f1,ans2[pos]=f2;
	return 0;
}
