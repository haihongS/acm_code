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
const int maxn=10+9;
const int inf=1e9+9;

struct II
{
    int a,b,c,p,r;
}num[maxn];

int n,m;
int flag,ans;
int use[maxn],G[maxn][maxn],ff[maxn];

int dfs(int loca);
int go(int loca,int state,int sum);

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(G,-1,sizeof(G));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d%d",&num[i].a,&num[i].b,&num[i].c,&num[i].p,&num[i].r);
            num[i].a--,num[i].b--,num[i].c--;
            G[num[i].a][num[i].b]=1;
        }

        if(n==1){printf("0\n");continue;}

        flag=0;
        memset(use,0,sizeof(use));
        dfs(0);
        if(flag==0)
        {
            printf("impossible\n");continue;
        }

        memset(ff,0,sizeof(ff));
        ans=inf;
        for(int i=0;i<m;i++)
        {
            if(num[i].a==0)
            {
                ff[i]++;
                go(i,(1<<num[i].a)|(1<<num[i].b),num[i].r);
                ff[i]--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

int go(int loca,int state,int sum)
{
    if(num[loca].b==n-1)
    {
        if(sum<ans)
            ans=sum;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        if(ff[i]>2) continue;
        if(num[i].a!=num[loca].b) continue;

        int t1=1<<(num[i].a);
        int t2=1<<(num[i].b);
        int t3=1<<(num[i].c);
        int tmp=num[i].r;
        if(state & t3)
            tmp=num[i].p;

        ff[i]++;
        go(i,(state|t1)|t2,sum+tmp);
        ff[i]--;
    }
    return 0;
}

int dfs(int loca)
{
    if(flag) return 0;
    if(loca==n-1) {flag=1;return 0;}
    for(int i=0;i<n;i++)
    {
        if(use[i]==1) continue;
        if(G[loca][i]==-1) continue;
        use[i]=1;
        dfs(i);
        if(flag) return 0;
    }
    return 0;
}
