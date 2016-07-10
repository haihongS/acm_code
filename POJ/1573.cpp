#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int maxn=2e4+9;
const int inf=2e9+9;

char mapp[20][20];
int flag[20][20];
int n,m,s,go,ans,ax,ay;

int dfs(int x,int y,int cnt);

int main()
{
    while(scanf("%d%d%d",&n,&m,&s) && n+m+s)
    {
        s--;
        for(int i=0;i<n;i++)
            scanf("%s",mapp[i]);
        memset(flag,-1,sizeof(flag));
        go=0;
        dfs(0,s,0);
        if(go==1)
        {
            printf("%d step(s) to exit\n",ans);
        }
        else if(go==2)
        {
            printf("%d step(s) before a loop of %d step(s)\n",flag[ax][ay],ans-flag[ax][ay]);
        }
    }
    return 0;
}

int dfs(int x,int y,int cnt)
{
    if(go!=0)
        return 0;
    if(x<0 || y<0 || x>=n || y>=m)
    {
        go=1;
        ans=cnt;
        return 0;
    }

    if(flag[x][y]!=-1)
    {
        go=2;
        ans=cnt;
        ax=x,ay=y;
        return 0;
    }

    flag[x][y]=cnt;

    if(mapp[x][y]=='N')
        dfs(x-1,y,cnt+1);
    else if(mapp[x][y]=='S')
        dfs(x+1,y,cnt+1);
    else if(mapp[x][y]=='W')
        dfs(x,y-1,cnt+1);
    else if(mapp[x][y]=='E')
        dfs(x,y+1,cnt+1);
    return 0;
}
