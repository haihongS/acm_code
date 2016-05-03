/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月03日 星期二 21时15分58秒
File Name     :2104.cpp
Blog          :http://haihongblog.com
************************************************ */

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
const int maxn=1e5+9;
const int inf=1e9+9;

int n,m,len;
int num[maxn],bb[maxn];
vector<int> aha[maxn];

int bi(int loca,int v);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++) scanf("%d",&num[i]);
		len=(int)sqrt(1.0*n*log(1.0*n));
		for(int i=0;i<=n;i++) aha[i].clear();
		for(int i=0;i<n;i++)
		{
			bb[i]=num[i];
			aha[i/len].push_back(num[i]);
		}
		sort(bb,bb+n-1);
		for(int i=0;i<=n/len;i++) sort(aha[i].begin(),aha[i].end());

		while(m--)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			l--,r--;
			int low=0,up=n-1,mid;
			int cnt=0,ans;
			while(low<=up)
			{
				mid=low+(up-low)/2;
				int tl=l,tr=r;
				while(tl%len!=0 && tl<tr)
				{
					if(num[tl]<bb[mid]) cnt++;
					tl++;
				}
				while(tr%len!=0 && tl<tr)
				{
					if(num[tr]<bb[mid]) cnt++;
					tr--;
				}
				if(num[tr]<bb[mid]) cnt--;

				for(int i=tl/len+1;i<=tr/len;i++)
				{
					int tmp=bi(i,bb[mid]);
					cnt+=tmp+1;
				}
				if(cnt>=k)
				{
					up=mid-1;
				}
				else if(cnt<k-1)
					low=mid+1;
				else
				{
					ans=mid;break;
				}
			}
			printf("%d\n",bb[ans]);
		}

	}
    return 0;
}

int bi(int loca,int v)
{
	int lt=-1,rt=aha[loca].size()-1,mid,ans;
	ans=rt;
	while(lt<=rt)
	{
		mid=lt+(rt-lt)/2;
		if(aha[loca][mid]>=v)
		{
			rt=mid-1;
			ans=min(ans,mid);
		}
		else
			lt=mid+1;
	}
	return ans;
}
