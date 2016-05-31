#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=60+9;
const int inf=1e9+9;

struct mat
{
	ll v[maxn][maxn];
}E,p;

int n,k;
ll m;

mat mul(mat a,mat b);
mat quick_pow();

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
		{
			E.v[i][j]=p.v[i][j]=0;
			if(i==j) E.v[i][j]=1;
		}
    while(~scanf("%d%d%lld",&n,&k,&m))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%lld",&p.v[i][j]);
				p.v[i][j]%=m;
			}
		for(int i=0;i<n;i++)
			for(int j=n;j<2*n;j++)
				p.v[i][j]=0;
		for(int i=n;i<2*n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i-n==j) p.v[i][j]=1;
				else p.v[i][j]=0;
			}
			for(int j=n;j<2*n;j++)
			{
				if(i==j) p.v[i][j]=1;
				else p.v[i][j]=0;
			}
		}

		mat ans=quick_pow();


		for(int i=n;i<2*n;i++)
		{
			for(int j=0;j<n;j++)
			{
				ll ss=ans.v[i][j];
				if(i-n==j)
					ss=(ss-1+m)%m;
				if(j==0) printf("%lld",ss%m);
				else printf(" %lld",ss%m);
			}
			printf("\n");
		}
	}
    return 0;
}

mat quick_pow()
{
	mat ans=E;
	int x=k+1;
	while(x)
	{
		if(x&1)
			ans=mul(ans,p);
		p=mul(p,p);
		x>>=1;
	}
	return ans;
}

mat mul(mat a,mat b)
{
	mat c;
	for(int i=0;i<2*n;i++)
	{
		for(int j=0;j<2*n;j++)
		{
			ll tmp=0;
			for(int k=0;k<2*n;k++)
			{
				tmp+=a.v[i][k]*b.v[k][j];
				tmp%=m;
			}
			c.v[i][j]=tmp;
		}
	}
	return c;
}

