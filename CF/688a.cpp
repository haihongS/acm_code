#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

int main()
{
	int n,d;
	while(~scanf("%d%d",&n,&d))
	{
		int ans=0;
		int cnt=0;
		for(int i=0;i<d;i++)
		{
			char num[200];
			scanf("%s",num);
			int len=strlen(num);
			int tmp=0;
			for(int j=0;j<len;j++)
			{
				tmp+=num[j]-'0';
			}
			if(tmp==n)
				cnt=0;
			else
				cnt+=1;
			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}
