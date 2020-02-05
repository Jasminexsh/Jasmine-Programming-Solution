#include<stdio.h>
#include<string.h>

int main()
{
	char A[1001]={0};
	int B,Q,R=0;
	scanf("%s %d",&A,&B);
	int num=0;
	int j;
	for(j=0;j<strlen(A);j++)
	{
		Q=(10*R+(A[j]-'0'))/B;
		if(!(Q==0 && j==0 && strlen(A)>1))
		{
			printf("%d",Q);
		}
		R=(10*R+(A[j]-'0'))%B; 
	}
	printf(" %d\n",R);
	return 0;
}
