	break;
			}
		}
	}
	if(flag==-1)
		printf("composite\n");
	else
	{
		int tmp=flag;
		for(int i=0;i<5;i++)
		{
			tmp*=flag;
			printf("%d\n",tmp);
			fflush(stdout);
			string jj;
			cin>>jj;
			if(jj=="yes")
			{
				flag=-1;
				break;
			}
		}
		if(flag==-1)
			printf("composite\n");
		else
			printf("prime\n");
	}

	return 0;
}

int pre()
{
	for(int i=2;i<150;i++)
	{
		int flag=1;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			prime[cnt++]=i;
	}
	return 0;
}
