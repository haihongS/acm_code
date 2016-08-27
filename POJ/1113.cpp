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

const int maxn=3000+9;
const int inf=2e9+9;
const double pi=3.141592653;

struct II
{
	int x,y;
}num[maxn],go[maxn];

int graham(int n);
int cross(II a,II b,II c);
int cmp(II a,II b);
double dis(II a,II b);

int main()
{
	int n,l;
	while(~scanf("%d%d",&n,&l))
	{
		for(int i=0;i<n;i++)
			scanf("%d%d",&num[i].x,&num[i].y);
		sort(num,num+n,cmp);
		int len=graham(n);
		double ans=0;
		ans+=2.0*pi*l;
		go[len]=go[0];
		for(int i=0;i<len;i++)
		{
			ans+=dis(go[i],go[i+1]);
		}
		printf("%d\n",(int)(ans+0.5));

	}
	return 0;
}

double dis(II a,II b)
{
	double ans=0;
	ans=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	ans=sqrt(1.0*ans);
	return ans;
}

int graham(int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		while(cnt>1 && cross(go[cnt-2],go[cnt-1],num[i])<=0)
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
