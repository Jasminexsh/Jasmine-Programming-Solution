#include<stdio.h>
#include<math.h>
int length(int m);

int main()
{
	int a,da,b,db;
	scanf("%d %d %d %d",&a,&da,&b,&db);
	int digita[10]={0},digitb[10]={0};
	int i=0;
	while(a!=0)
	{
		digita[i]=a%10;
		a/=10;
		i++;
	}
	
	int j=0;
	while(b!=0)
	{
		digitb[j]=b%10;
		b/=10;
		j++;
	}
	int lena = sizeof(digita)/sizeof(digita[0]);
	int counta=0,suma=0;
	for(i=0;i<lena;i++)
	{
		if(da==digita[i])
		{
			counta++;
				suma+=da*pow(10,counta-1);
		}
	}
	int lenb = sizeof(digitb)/sizeof(digitb[0]);
	int countb=0,sumb=0;
	for(j=0;j<lenb;j++)
	{
		if(db==digitb[j])
		{
			countb++;
			sumb+=db*pow(10,countb-1);
		}
	}
	int sum;
	sum = suma+sumb;
	printf("%d",sum);
	return 0;
}
