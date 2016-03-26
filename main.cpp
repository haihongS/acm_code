#include<bits/stdc++.h>
using namespace std;
const int N=1024;
typedef long long LL;
const int maxn=2e5+9;

int main()
{
    int h1,h2,a,b;
    while(~scanf("%d%d%d%d",&h1,&h2,&a,&b))
    {
        int loca=h1,cnt=0;
        loca+=a*8;
        if(loca>=h2)
        {
            printf("%d\n",cnt);continue;
        }
        loca-=12*b;
		if(a<b) {
			cnt=-1;
			printf("%d\n",cnt);continue;
		}
        cnt++;
        while(loca<h2)
        {
            if(cnt>maxn)
            {
                cnt=-1;
                break;
            }
            loca+=12*a;
            if(loca>=h2) break;
            loca-=b*12;
            //if(loca<0) loca=0;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
