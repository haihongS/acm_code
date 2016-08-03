#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e6+100;
const int go=1e6+2;

int num[maxn];
int lt[maxn],last[maxn],len[maxn];
int dp[maxn][22];
int n,m;

int init();
int query(int l,int r);

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			num[i]+=go;
		}
		lt[1]=1,last[num[1]]=1;
		for(int i=2;i<=n;i++)
		{
			lt[i]=max(lt[i-1],last[num[i]]+1);
			last[num[i]]=i;
		}
		for(int i=1;i<=n;i++)
			len[i]=i-lt[i]+1;
		init();

		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x++,y++;
			int low,up,mid,ans;
			low=x,up=y,ans=y;
			while(low<=up)
			{
				mid=low+(up-low)/2;
				if(lt[mid]>=x)
				{
					ans=min(ans,mid);
					up=mid-1;
				}
				else
					low=mid+1;
			}
			if(lt[ans]>x)
				ans--;
			int cnt;
			cnt=ans-x+1;
			if(ans<y)
				cnt=max(cnt,query(ans+1,y));

			printf("%d\n",cnt);
		}
	}
	return 0;
}

int query(int l,int r)
{
	int tmp=log(r-l+1)/log(2.0);
	return max(dp[l][tmp],dp[r-(1<<tmp)+1][tmp]);
}

int init()
{
	for(int i=1;i<=n;i++)
		dp[i][0]=len[i];
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+(1<<j)-1<=n)
				dp[i][j]=max(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
		}
	}
	return 0;
}

