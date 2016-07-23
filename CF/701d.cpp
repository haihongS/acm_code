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
	int n,l,v1,v2,k;
	while(~scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k))
	{
		double m;
		if(n%k==0) m=n/k;
		else m=n/k+1;
		double p=1.0*l;
		p/=1.0*m-(m-1)*1.0*(v2-v1)/(v1+v2);
		double t=1.0*p/v2+1.0*(l-p)/v1;
		printf("%.8lf\n",t);
	}
	return 0;
}
