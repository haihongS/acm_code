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
const int MAXN=1000;
const int mod = 3;

int A[MAXN][MAXN],free_x[MAXN],x[MAXN];


int exgcd(int a,int b,int &x,int &y){
    if(!b){x = 1; y = 0; return a;}
    else{
        int r = exgcd(b,a%b,y,x);
        y -= x * (a/b);
        return r;
    }
}
int lcm(int a,int b){
    int x = 0, y =0;
    return a / exgcd(a,b,x,y) * b;
}

void Gauss(int n,int m){
    int r,c;
    for(r=0,c=0;r<n && c<m;c++){
        int maxr = r;
        for(int i=r+1;i<n;i++) if(abs(A[i][c]) > abs(A[maxr][c])) maxr = i;
        if(maxr != r) for(int i=c;i<=m;i++) swap(A[r][i],A[maxr][i]);
        if(!A[r][c]) continue;
        for(int i=r+1;i<n;i++) if(A[i][c]){
            int d = lcm(A[i][c],A[r][c]);
            int t1 = d / A[i][c], t2 = d / A[r][c];
            for(int j=c;j<=m;j++)
                A[i][j] = ((A[i][j] * t1 - A[r][j] * t2) % mod + mod) % mod;
        }
        r++;
    }
    for(int i=r;i<n;i++) if(A[i][m]) return ;
    for(int i=r-1;i>=0;i--){
        x[i] = A[i][m];
        for(int j=i+1;j<m;j++){
            x[i] = ((x[i] - A[i][j] * x[j]) % mod + mod) % mod;
        }
        int x1 = 0,y1 = 0;
        int d = exgcd(A[i][i],mod,x1,y1);
        x1 = ((x1 % mod) + mod) % mod;
        x[i] = x[i] * x1 % mod;
    }
}
void Gauss_init(){
    memset(A,0,sizeof A); memset(free_x,0,sizeof free_x); memset(x,0,sizeof x);
}

const int maxn=33;

int mapp[maxn][maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Gauss_init();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&mapp[i][j]);
            }
        }
        int index=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                A[index][n*m]=(mod-mapp[i][j])%mod;
                A[index][i*m+j]=2;
                if(i>0) A[index][(i-1)*m+j]=1;
                if(i+1<n) A[index][(i+1)*m+j]=1;
                if(j>0) A[index][i*m+j-1]=1;
                if(j+1<m) A[index][i*m+j+1]=1;
                index++;
            }
        }
        Gauss(n*m,n*m);
        int ans=0;
        for(int i=0;i<n*m;i++)
            ans+=x[i];
        printf("%d\n",ans);
        for(int i=0;i<n*m;i++)
        {
            while(x[i]>0)
            {
                printf("%d %d\n",i/m+1,i%m+1);
                x[i]--;
            }
        }
    }
    return 0;
}
