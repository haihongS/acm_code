#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;


int n;
int gg[maxn*4],num[maxn];
map<int,ll> aha;

int gcd(int x,int y);
int build(int node,int l,int r);
int query(int node,int l,int r,int L,int R);

int main()
{
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		scanf("%d",&n);
		build(0,1,n);

		aha.clear();
		for(int i=1;i<=n;i++)
		{
			if(i!=n && gcd(num[i],num[i+1])==1)
			{
				aha[num[i]]+=1;
				aha[1]+=n-i;
				continue;
			}
			//aha[num[i]]+=1;
			int loca=i,last=num[i];
			while(1)
			{
				int lt=loca,rt=n,mid,ans=lt;
				while(lt<=rt)
				{
					mid=lt+(rt-lt)/2;
					if(query(0,1,n,i,mid)>=last)
					{
						lt=mid+1;
						ans=max(ans,mid);
					}
					else
						rt=mid-1;
				}
				aha[last]+=ans-loca+1;
				loca=ans+1;
				if(loca>n) break;
				last=query(0,1,n,i,loca);
			}
		}
		
		int q;
		scanf("%d",&q);
		printf("Case #%d:\n",cas++);
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			int tmp=query(0,1,n,l,r);
			printf("%d %lld\n",tmp,aha[tmp]);
		}

	}
	return 0;
}

int query(int node,int l,int r,int L,int R)
{
	if(R<l || L>r) return 1;
	if(L<=l && r<=R) return gg[node];
	int mid=l+(r-l)/2;
	int v=-1;
	if(L<=mid)
		v=query(2*node+1,l,mid,L,R);
	if(R>mid)
	{
		if(v==-1)
			v=query(2*node+2,mid+1,r,L,R);
		else
			v=gcd(v,query(2*node+2,mid+1,r,L,R));
	}
	return v;
}

int build(int node,int l,int r)
{
	if(l==r)
	{
		int x;
		scanf("%d",&x);
		gg[node]=num[l]=x;
		return x;
	}
	int mid=(l+r)/2;
	int g1=build(2*node+1,l,mid);
	int g2=build(2*node+2,mid+1,r);
	gg[node]=gcd(g1,g2);
	return gg[node];
}

int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

