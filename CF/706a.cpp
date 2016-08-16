#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;


int main()
{
	double a,b;
	while(~scanf("%lf%lf",&a,&b))
	{
		int n;
		scanf("%d",&n);
		double ans=100000;
		for(int i=0;i<n;i++)
		{
			double x,y,v;
			scanf("%lf%lf%lf",&x,&y,&v);
			double tmp=sqrt((x-a)*(x-a)+(y-b)*(y-b));
			tmp=tmp/v;
			ans=min(ans,tmp);
		}
		printf("%.8f\n",ans);
	}
	return 0;
}
