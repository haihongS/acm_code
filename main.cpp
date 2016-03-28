#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
//const int N=5*1024;
const double eps=1e-8;
const int N=100000+10;

string t1,t2,t3;
int next[N];

int kmp(string p,string t,int plen,int tlen);
void findnext(string p,int plen);
int pre(string x,string y,int xlen,int ylen);
int zu(string x,string y,string z,int xlen,int ylen,int zlen);

int main()
{
    while(cin>>t1>>t2>>t3){
    int len1,len2,len3;
    len1=t1.length(),len2=t2.length(),len3=t3.length();
    if(len2>len1)
    {
        swap(t2,t1);swap(len2,len1);
    }
    if(len3>len1)
    {
        swap(t3,t1);swap(len3,len1);
    }
    if(len3>len2)
    {
        swap(t3,t2);swap(len3,len2);
    }
    int ans=0;
    int use=kmp(t2,t1,len2,len1);
    if(use>=1)
    {
        int use2=kmp(t3,t1,len3,len1);
        if(use2>=1)
        {
            ans=len1;
        }
        else
        {
            int p1=pre(t3,t1,len3,len1);
            ans=len1+len3-p1;
            int p2=pre(t1,t3,len1,len3);
			ans=min(ans,len3+len1-p2);
        }
    }
    else
    {
        int use2=kmp(t3,t2,len3,len2);
        if(use2>=1)
        {
            int p1=pre(t2,t1,len2,len1);
            ans=len2+len1-p1;
            int p2=pre(t1,t2,len1,len2);
            ans=min(ans,len2+len1-p2);
        }
        else
        {
            int use3=kmp(t3,t1,len3,len1);
            if(use3>=1)
            {
                int p1=pre(t2,t1,len2,len1);
                ans=len2+len1-p1;
                int p2=pre(t1,t2,len1,len2);
                ans=min(ans,len2+len1-p2);
            }
            else
            {
                ans=zu(t1,t2,t3,len1,len2,len3);
                ans=min(ans,zu(t1,t3,t2,len1,len3,len2));
                ans=min(ans,zu(t2,t1,t3,len2,len1,len3));
                ans=min(ans,zu(t2,t3,t1,len2,len3,len1));
                ans=min(ans,zu(t3,t1,t2,len3,len1,len2));
                ans=min(ans,zu(t3,t2,t1,len3,len2,len1));
            }
        }
    }
    printf("%d\n",ans);
	}
    return 0;
}

int zu(string x,string y,string z,int xlen,int ylen,int zlen)
{
    int len=0;
    //int xlen=x.length(),ylen=y.length(),zlen=z.length();
    int p=pre(x,y,xlen,ylen);
	len=xlen+ylen-p;
	for(int i=p;i<ylen;i++)
		x=x+y[i];
	int q=pre(x,z,xlen,zlen);
	len=len+zlen-q;
	return len;
}

//x--y
int pre(string x,string y,int xlen,int ylen)
{
    //int xlen=x.length();
    //int ylen=y.length();
	if(xlen>ylen)
	{
		findnext(y,ylen);
		int i=0;
		for(int j=xlen-ylen;j<xlen;j++)
		{
			while(i!=-1 && y[i]!=x[j]) i=next[i];
			i++;
			if(j==xlen-1)
				return i;
		}
	}
	else
	{
		findnext(y,ylen);
		int i=0;
		for(int j=0;j<xlen;j++)
		{
			while(i!=-1 && y[i]!=x[j]) i=next[i];
			i++;
			if(j==xlen-1)
				return i;
		}
	}
}


//int kmp(char *p,char *t,int *next)
int kmp(string p,string t,int plen,int tlen)
{
    findnext(p,plen);
    int i=0,j=0,cnt=0;
    //int plen=strlen(p),tlen=strlen(t);
    //int plen=p.length(),tlen=t.length();
    if(tlen<plen) return cnt;
    while(j<tlen)
    {
        while(i!=-1&&p[i]!=t[j])
            i=next[i];
        i++;j++;
        if(i>=plen)
        {
            cnt++;
            i=0;
        }
    }
    return cnt;
}

//void findnext(char *p,int *next)
void findnext(string p,int len)
{
    int i=0,k=-1;
    //int len=strlen(p);
    //int len=p.length();
    next[0]=-1;
    while(i<len)
    {
        while(k>=0&&p[k]!=p[i])
            k=next[k];
        i++;
        k++;
        if(i==len) break;
        //不优化版采用注释中的代码
        if(p[i]==p[k])
            next[i]=next[k];
        else
            next[i]=k;
        //next[i]=k;
    }
}

