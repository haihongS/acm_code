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
const int inf=2e9+9;


int main()
{
    int a,v1,v2;
    while(~scanf("%d%d%d",&a,&v1,&v2))
    {
        if(a==0)
        {
            printf("0\n");
            continue;
        }
        if(v1<=v2)
        {
            printf("Infinity\n");
            continue;
        }
        double ans=1.0*v1*a/(v1*v1-v2*v2);
        printf("%.6f\n",ans);
    }
    return 0;
}
