#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=3e5+9;
const int inf=2e9+9;
const ll mod=1000000007;

int nx[maxn];
char S[maxn], T[maxn];
int slen, tlen;
int flag[maxn];
ll dp[maxn];

void get_next()
{
    int j=-1,i=0; nx[0]=-1;
    while(i<tlen)
    {
        if(j==-1||T[i]==T[j]) i++, j++, nx[i]=j;
        else j=nx[j];
    }
}

void kmp(){
    get_next();
    int i=0,j=0;
    while(i<slen){
        if(j==-1||S[i]==T[j])
        {
            if(j==tlen-1)
                flag[i]=1;
            i++ ,j++;
        }
        else j=nx[j];
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        scanf("%s",S);
        scanf("%s",T);
        slen=strlen(S),tlen=strlen(T);
        for(int i=0;i<maxn;i++)
        {
            dp[i]=flag[i]=0;
        }
        kmp();
        int i=0;
        for(;flag[i]!=1;i++)
            dp[i]=1;
        dp[i]=2;
        i++;
        for(;i<slen;i++)
        {
            if(flag[i]==0)
                dp[i]=dp[i-1];
            else
                dp[i]=dp[i-1]+dp[i-tlen];
            dp[i]%=mod;
        }
        printf("Case #%d: ",cas++);
        printf("%lld\n",dp[slen-1]);
        
    }

    return 0;
}
