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
const int inf=1000000;

int num[maxn],lt[maxn],rt[maxn];
int bi[maxn];

struct II
{
    int v,id;
}go[maxn];

int lowbit(int x);
int sum(int x);
int change(int loca,int v);
int cmp(const II&x,const II&y);

int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        for(int i=0;i<maxn;i++)
        {
            lt[i]=rt[i]=bi[i]=0;
        }
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            int tmp=sum(num[i]-1);
            rt[i]=num[i]-tmp-1;
            int tmp2=sum(n);
            lt[i]=tmp2-tmp;
            change(num[i],1);
        }
        /*
        for(int i=0;i<n;i++)
        {
            printf("**%d %d %d\n",i,lt[i],rt[i]);
        }
        continue;
        */
        printf("Case #%d: ",cas++);

        for(int i=0;i<n;i++)
        {
            int tmp=i+rt[i];
            tmp=max(tmp-i,tmp-(tmp-lt[i]));
            go[i].v=tmp,go[i].id=num[i];
        }
        sort(go,go+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                printf("%d",go[i].v);
            else
                printf(" %d",go[i].v);
        }
        printf("\n");

    }
    return 0;
}

int cmp(const II&x,const II&y)
{
    return x.id<y.id;
}

int change(int loca,int v)
{
    while(loca<maxn)
    {
        bi[loca]+=v;
        loca+=lowbit(loca);
    }
    return 0;
}

int sum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=bi[x];
        x-=lowbit(x);
    }
    return ans;
}

int lowbit(int x)
{
    return x&(-x);
}
