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

char mapp[50][50][50];
int flag[50][50][50];

int l,n,m,sx,sy,sz;
int ans;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

struct II
{
    int x,y,z;
    int t;
};

int bfs();

int main()
{
    while(scanf("%d%d%d",&l,&n,&m) && l+n+m)
    {
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%s",mapp[i][j]);
        }

        for(int i=0;i<l;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<m;k++)
                {
                    if(mapp[i][j][k]=='S')
                    {
                        sx=j,sy=k,sz=i;
                        mapp[i][j][k]='.';
                    }
                }
        memset(flag,-1,sizeof(flag));
        ans=-1;
        bfs();
        if(ans==-1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}

int bfs()
{
    queue<II> aha;
    while(!aha.empty())
        aha.pop();
    II fir;
    fir.x=sx,fir.y=sy,fir.z=sz,fir.t=0;
    aha.push(fir);
    while(!aha.empty())
    {
        II tp=aha.front();
        aha.pop();
        //printf("--%d %d %d\n",tp.x,tp.y,tp.z);
        if(mapp[tp.z][tp.x][tp.y]=='E')
        {
            ans=tp.t;
            break;
        }
        if(flag[tp.z][tp.x][tp.y]!=-1)
            continue;

        flag[tp.z][tp.x][tp.y]=1;
        for(int i=0;i<4;i++)
        {
            int nx,ny,nz;
            nx=tp.x+dx[i],ny=tp.y+dy[i],nz=tp.z;
            if(nx<0 || nx>=n || ny<0 || ny>=m || nz<0 || nz>=l)
                continue;
            if(flag[nz][nx][ny]==1)
                continue;
            if(mapp[nz][nx][ny]=='#')
                continue;
            //flag[nz][nx][ny]=1;
            II next;
            next.x=nx,next.y=ny,next.z=nz,next.t=tp.t+1;
            aha.push(next);
            //printf("%d %d %d\n",next.x,next.y,next.z);
        }
        int nx,ny,nz;
        nx=tp.x,ny=tp.y;
        nz=tp.z-1;
        if(nz>=0)
        {
            if(flag[nz][nx][ny]==-1 && mapp[nz][nx][ny]!='#')
            {
                //flag[nz][nx][ny]=1;
                II next;
                next.x=nx,next.y=ny,next.z=nz,next.t=tp.t+1;
                aha.push(next);
                //printf("%d %d %d\n",next.x,next.y,next.z);
            }
        }
        nz=tp.z+1;
        if(nz<l)
        {
            if(flag[nz][nx][ny]==-1 && mapp[nz][nx][ny]!='#')
            {
                //flag[nz][nx][ny]=1;
                II next;
                next.x=nx,next.y=ny,next.z=nz,next.t=tp.t+1;
                aha.push(next);
                //printf("%d %d %d\n",next.x,next.y,next.z);
            }
        }
    }
    return 0;
}




