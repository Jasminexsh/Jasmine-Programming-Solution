#include<stdio.h>
int main()
{
	int N;
	scanf("%d ",&N);
	int a[N]; 
	int i,j;
	
	//初始化 
	int sum1=0,sum2=0,temp=1;
	int count2=0,count3=0,count4=0,sum4=0;
	int max5=0;
	
	for(i=0;i<N;i++)
	{
		if(i!=N-1)
		{
			scanf("%d ",&a[i]);
		}
		else
		{
			scanf("%d",&a[i]);
		}
	}
	
	for(j=0;j<N;j++)
	{
		
		if(a[j]%5==0 && a[j]%2==0)
		{
			sum1+=a[j];
		}
		if(a[j]%5==1)
		{
            count2++;
			sum2+=a[j]*temp;
			temp*=-1;
		}
		if(a[j]%5==2)
		{
			count3++;
		}
		if(a[j]%5==3)
		{
			count4++;
			sum4+=a[j];
		}
		if(a[j]%5==4)
		{
			if(a[j]>max5)
			{
				max5 = a[j];
			}
		}
	}
	
	if(sum1==0){		
		printf("N ");}
	else{
		printf("%d ",sum1);}
		
	//交错求和结果可能为0
    if(count2==0){
		printf("N ");}
	else{
		printf("%d ",sum2);}
			
	if(count3==0){
		printf("N ");}
	else{
		printf("%d ",count3);}
		
	if(sum4==0){
		printf("N ");}
	else{
		printf("%.1lf ",1.0*sum4/count4);}
		
	if(max5==0){
		printf("N");}
	else{
		printf("%d",max5);}
	return 0;
}
