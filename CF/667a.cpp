#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e6+100;
const double pi=acos(-1.0);

int main()
{
	double d,h,v,e;
	while(~scanf("%lf%lf%lf%lf",&d,&h,&v,&e))
	{
		double tmp=1.0*v/(pi*(d/2.0)*(d/2.0));
		if(tmp<=e)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%.8f\n",1.0*h/(tmp-e));

	}
	return 0;
}
