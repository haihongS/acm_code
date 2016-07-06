#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

char num[10][10];
char aha[5]={'A','C','G','T'};
int len[10];
int maxlen,flag,n;

int dfs(int cnt,int ok[10]);

int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        maxlen=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",num[i]);
            len[i]=strlen(num[i]);
            maxlen=max(maxlen,len[i]);
        }
        flag=0;
        int use[10];
        memset(use,0,sizeof(use));
        for(int i=0;i<40;i++)
        {
            dfs(0,use);
            if(flag==1)
                break;
            maxlen++;
        }
        printf("%d\n",maxlen);

    }
    return 0;
}

int dfs(int cnt,int ok[10])
{
    if(flag==1 || cnt>maxlen)
        return 0;

    int tmp=0;
    for(int i=0;i<n;i++)
    {
        tmp=max(tmp,len[i]-ok[i]);
    }
    if(tmp==0)
    {
        flag=1;
        return 0;
    }
    if(cnt+tmp>maxlen)
        return 0;
    for(int i=0;i<4;i++)
    {
        int tflag=0;
        int nextok[10];
        for(int j=0;j<n;j++)
        {
            nextok[j]=ok[j];
            if(ok[j]==len[j])
                continue;
            if(aha[i]==num[j][ok[j]])
            {
                nextok[j]+=1;
                tflag=1;
            }
        }
        if(tflag)
            dfs(cnt+1,nextok);
        if(flag==1)
            return 0;
    }
    return 0;
}
