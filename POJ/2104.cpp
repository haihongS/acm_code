/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月03日 星期二 21时15分58秒
File Name     :2104.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const int inf=1e9+9;

int n,m,len;
int num[maxn],bb[maxn];
vector<int> aha[maxn];

int bi(int loca,int v);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++) scanf("%d",&num[i]);
        //len=(int)sqrt(1.0*n*log(1.0*n));
        len=1000;
        for(int i=0; i<=n/len; i++) aha[i].clear();
        for(int i=1; i<=n; i++)
        {
            aha[i/len].push_back(num[i]);
        }
        for(int i=0; i<=n/len; i++) sort(aha[i].begin(),aha[i].end());

        while(m--)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            for(int i=l;i<=r;i++)
            {
                bb[i-l+1]=num[i];
            }
            sort(bb+1,bb+1+r-l+1);
            int low=1,up=r-l+1,mid;
            int cnt=0,ans=up;
            while(low<=up)
            {
                mid=low+(up-low)/2;
                int tl=l,tr=r;
                while(tl%len!=0 && tl<tr)
                {
                    if(num[tl]<bb[mid]) cnt++;
                    tl++;
                }
                while(tr%len!=0 && tl<tr)
                {
                    if(num[tr]<bb[mid]) cnt++;
                    tr--;
                }
                if(tr-tl+1<=len)
                {
                    for(int i=tl; i<=tr; i++)
                    {
                        if(num[i]<bb[mid]) cnt++;
                    }
                }
                else
                {
                    for(int i=tl/len; i<(tr+1)/len; i++)
                    {
                        int tmp=bi(i,bb[mid]);
                        cnt+=tmp;
                    }
                }
                if(cnt>k-1)
                {
                    up=mid-1;
                }
                else if(cnt==k-1)
                {
                    ans=mid;break;
                }
                else
                    low=mid+1;

                cnt=0;
            }
            printf("%d\n",bb[ans]);
        }
    }
    return 0;
}

int bi(int loca,int v)
{
    int lt=0,rt=aha[loca].size()-1,mid,ans;
    ans=rt;
    while(lt<=rt)
    {
        mid=lt+(rt-lt)/2;
        if(aha[loca][mid]>=v)
        {
            rt=mid-1;
            ans=min(ans,mid);
        }
        else
            lt=mid+1;
    }
    return ans;
}
