#include<stdio.h>
int main()
{
	int K1,K2;
	double a1[1001]={0};
	double a2[1001]={0};
	
	int N1,N2;
	double aN1,aN2;
	
	scanf("%d",&K1);

	for(int i=0;i<K1;i++)
	{
		if(i!=K1-1) 
			scanf("%d %lf ",&N1,&aN1);	
		else
			scanf("%d %lf",&N1,&aN1);
		
		a1[N1]=aN1;
	}
	
	scanf("%d ",&K2);
	for(int j=0;j<K2;j++)
	{
		if(j!=K2-1) 
			scanf("%d %lf ",&N2,&aN2);
		else
			scanf("%d %lf",&N2,&aN2);
		
		a2[N2]=aN2;
	}
	
	double sum[1001]={0};
	int count=0;
	for(int k=1000;k>=0;k--)
	{
		sum[k]=a1[k]+a2[k];
		if(sum[k]!=0)
		{
			count++;
		}
	}
	
	if(count!=0)
		printf("%d ",count);
	else
		printf("%d",count);
		
	for(int l=1000;l>=0;l--)
	{
		if(sum[l]!=0)
		{
			count--;
			if(count!=0)
				printf("%d %.1lf ",l,sum[l]);
			else
				printf("%d %.1lf",l,sum[l]);
		}
	}
	return 0;
}
