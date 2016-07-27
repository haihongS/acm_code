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

map<ll,int> aha;

struct II
{
    ll  x,y;
}num[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        aha.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&num[i].x,&num[i].y);
        }
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll tmp=abs(num[i].x-num[j].x)+abs(num[i].y-num[j].y);
                if(aha[tmp]==1)
                {
                    flag=1;break;
                }
                aha[tmp]=1;
            }
            if(flag==1) break;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

