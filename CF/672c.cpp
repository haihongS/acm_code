#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const double inf=2e15+9;

double ax,ay,bx,by,tx,ty;
double disa[maxn],disb[maxn],dis[maxn];

double Dis(double x1,double y1,double x2,double y2);

int main()
{
	while(~scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty))
	{
		int n;
		scanf("%d",&n);
		double sum=0;
		double ma,mb;
		int posa,posb;
		ma=mb=inf;
		for(int i=0;i<n;i++)
		{
			double x,y;
			scanf("%lf%lf",&x,&y);
			dis[i]=Dis(x,y,tx,ty);
			disa[i]=Dis(x,y,ax,ay);
			disb[i]=Dis(x,y,bx,by);
			sum+=dis[i]*2;

			if(disa[i]-dis[i]<ma)
			{
				ma=disa[i]-dis[i];
				posa=i;
			}
			if(disb[i]-dis[i]<mb)
			{
				mb=disb[i]-dis[i];
				posb=i;
			}
		}
		double ans=sum;
		ans=min(ans,sum-dis[posa]+disa[posa]);
		ans=min(ans,sum-dis[posb]+disb[posb]);
		if(ma<0 && mb<0)
		{
			if(posa!=posb)
			{
				ans=sum-dis[posa]+disa[posa]-dis[posb]+disb[posb];
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if(i==posa) continue;
					ans=min(ans,sum-dis[posb]+disb[posb]-dis[i]+disa[i]);
				}
				for(int i=0;i<n;i++)
				{
					if(i==posb) continue;
					ans=min(ans,sum-dis[posa]+disa[posa]-dis[i]+disb[i]);
				}
			}
		}
		else
		{
			if(ma<mb)
				ans=sum+ma;
			else
				ans=sum+mb;
		}
		printf("%.9f\n",ans);

	}
	return 0;
}

double Dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
