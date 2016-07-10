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

char ans[500][500];

int main()
{
    int s;
    long long n;
    while(scanf("%d",&s))
    {
        char duru[20];
        scanf("%s",duru);
        if(duru[0]=='0' && strlen(duru)==1 && s==0)
            break;
        int num[20];
        int len=strlen(duru);
        for(int i=0;i<len;i++)
            num[i]=duru[i]-'0';
        for(int i=0;i<500;i++)
            for(int j=0;j<500;j++)
                ans[i][j]=' ';

        for(int i=0;i<len;i++)
        {
            int lt=i*s+3*i,rt=(i+1)*s+3*i+1;
            if(num[i]==2 || num[i]==3 || num[i]==5 ||
               num[i]==6 || num[i]==7 || num[i]==8 || num[i]==9 ||
               num[i]==0)
            {
                for(int j=lt+1;j<rt;j++)
                    ans[0][j]='-';
            }
            if(num[i]==2 || num[i]==3 || num[i]==4 || num[i]==5
               || num[i]==6 || num[i]==8 || num[i]==9)
            {
                for(int j=lt+1;j<rt;j++)
                    ans[s+1][j]='-';
            }
            if(num[i]==2 || num[i]==3 || num[i]==5 || num[i]==6 ||
               num[i]==8 || num[i]==9 || num[i]==0)
            {
                for(int j=lt+1;j<rt;j++)
                    ans[2*s+2][j]='-';
            }
            if(num[i]==1 || num[i]==3 || num[i]==4 || num[i]==7 ||
               num[i]==8 || num[i]==9 || num[i]==0)
            {
                for(int j=1;j<2*s+2;j++)
                {
                    if(j==s+1) continue;
                    ans[j][rt]='|';
                }
            }
            if(num[i]==6 || num[i]==8 || num[i]==0)
            {
                for(int j=1;j<2*s+2;j++)
                {
                    if(j==s+1) continue;
                    ans[j][lt]='|';
                }
            }
            if(num[i]==2)
                for(int j=1;j<s+1;j++)
                    ans[j][rt]='|';
            if(num[i]==4 || num[i]==5 || num[i]==9)
                for(int j=1;j<s+1;j++)
                    ans[j][lt]='|';
            if(num[i]==2)
                for(int j=s+2;j<2*s+2;j++)
                    ans[j][lt]='|';
            if(num[i]==5 || num[i]==6)
                for(int j=s+2;j<2*s+2;j++)
                    ans[j][rt]='|';
        }
        for(int i=0;i<=2*s+2;i++)
        {
            for(int j=0;j<=len*s+3*(len-1)+1;j++)
                printf("%c",ans[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}






