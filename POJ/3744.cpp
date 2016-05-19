#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=1e3+9;
const double eps=1e-9;

struct matrix
{
    double m[2][2];
};

matrix I={  1,0,
            0,1,
         };
matrix x;

int n;
double p;
int num[20];

matrix mul(matrix a,matrix b);
matrix quick_pow(int y);

int main()
{
    while(~scanf("%d%lf",&n,&p))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        x.m[0][0]=p,x.m[0][1]=1;
        x.m[1][0]=1-p,x.m[1][1]=0;

        sort(num,num+n);
        if(num[0]==1)
        {
            printf("0.0000000\n");continue;
        }
        matrix ans;
        ans.m[0][0]=1,ans.m[0][1]=0;
        ans.m[1][0]=ans.m[1][1]=0;
        int last=1;
        for(int i=0;i<n;i++)
        {
            matrix tmp=quick_pow(num[i]-last);
            ans=mul(ans,tmp);
            ans.m[0][0]=0;
            last=num[i];
        }
        printf("%.7lf\n",ans.m[0][1]*(1-p));
    }
    return 0;
}

matrix quick_pow(int y)
{
    matrix ans=I;
    matrix tmp=x;
    while(y)
    {
        if(y&1)
            ans=mul(ans,tmp);
        y>>=1;
        tmp=mul(tmp,tmp);
    }
    return ans;
}

matrix mul(matrix a,matrix b)
{
    matrix ans;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            double tmp=0;
            for(int k=0;k<2;k++)
            {
                tmp+=a.m[i][k]*b.m[k][j];
            }
            ans.m[i][j]=tmp;
        }
    }
    return ans;
}
