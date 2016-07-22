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

int num[200];

int gcd(int x,int y);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(num,-1,sizeof(num));
        int n,m;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            num[x]=y;
        }
        int up,down;
        up=down=0;
        int last=0;
        for(int i=n;i>=3;i--)
        {
            if(num[i]==-1)
                num[i]=last;
            else
                last=num[i];
            down+=num[i];
        }
        last=100;
        for(int i=1;i<=2;i++)
        {
            if(num[i]==-1)
                num[i]=last;
            else
                last=num[i];
            down+=num[i],up+=num[i];
        }
        int gg=gcd(up,down);
        up/=gg,down/=gg;
        printf("%d/%d\n",up,down);
    }
    return 0;
}


int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
