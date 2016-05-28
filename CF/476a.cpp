/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月28日 星期六 14时27分21秒
File Name     :main.cpp
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(~scanf("%d",&n))
	{
		int minn,maxx;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
				minn=i;
			else if(x==n)
				maxx=i;
		}
		int tmp=min(minn,maxx);
		maxx=max(maxx,minn);
		minn=tmp;
		int ans=abs(maxx-minn);
		ans=max(ans,n-1-minn);
		ans=max(ans,maxx-0);
		printf("%d\n",ans);
	}
    return 0;
}
