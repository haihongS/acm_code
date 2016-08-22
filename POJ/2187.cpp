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

using namespace std;
typedef long long ll;
const int maxn=5e4+9;
const int inf=2e9+9;

struct II
{
	int x,y;
}num[maxn],go[maxn];


int cmp(II a,II b);
int graham(int n);
int cross(II a,II b,II c);
int dis(II a,II b);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&num[i].x,&num[i].y);
		}
		sort(num,num+n,cmp);
		int len=graham(n);
		int ans=0;
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				ans=max(ans,dis(go[i],go[j]));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

int dis(II a,II b)
{
	int t1=a.x-b.x,t2=a.y-b.y;
	return t1*t1+t2*t2;
}

int graham(int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		while(cnt>1 &&  cross(go[cnt-2],go[cnt-1],num[i])<=0)
			cnt--;
		go[cnt++]=num[i];
	}
	int tmp=cnt;
	for(int i=n-2;i>=0;i--)
	{
		while(cnt>tmp && cross(go[cnt-2],go[cnt-1],num[i])<=0)
			cnt--;
		go[cnt++]=num[i];
	}
	return cnt;
}

int cross(II a,II b,II c)
{
	II v1,v2;
	v1.x=b.x-a.x;
	v1.y=b.y-a.y;
	v2.x=c.x-b.x;
	v2.y=c.y-b.y;
	return v1.x*v2.y-v1.y*v2.x;
}

int cmp(II a,II b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

