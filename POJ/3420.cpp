#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=10;

int n;
ll m;

ll f[6]={1,1,5,11,36,95};

struct mat
{
    ll v[maxn][maxn];
}E,p;

mat mul(mat a,mat b);
mat quick_pow();

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("my.txt","w",stdout);
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<maxn;j++)
        {
            if(i==j) E.v[i][j]=1;
            else E.v[i][j]=0;
            p.v[i][j]=0;
        }
    }
    p.v[0][0]=1,p.v[0][1]=5,p.v[0][2]=1,p.v[0][3]=-1;
    p.v[1][0]=1;
    p.v[2][1]=1;
    p.v[3][2]=1;
    while(scanf("%d%lld",&n,&m))
    {
        if(n==0 && m==0) break;
        if(n<=4)
        {
            printf("%lld\n",f[n]%m);continue;
        }
	p.v[0][3]=-1+m;

        mat ans=quick_pow();

        ll go=0;
        for(int i=0;i<4;i++)
        {
            go+=ans.v[0][i]*f[3-i];
            go%=m;
        }
        printf("%lld\n",(go%m+m)%m);
    }
    return 0;
}

mat quick_pow()
{
    mat ans=E,a=p;
    int x=n-3;
    while(x)
    {
        if(x&1)
            ans=mul(ans,a);
        a=mul(a,a);
        x>>=1;
    }
    return ans;
}


mat mul(mat a,mat b)
{
    mat c;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            ll tmp=0;
            for(int k=0;k<4;k++)
            {
                tmp+=a.v[i][k]*b.v[k][j];
                tmp%=m;
            }
            c.v[i][j]=tmp;
        }
    }
    return c;
}
