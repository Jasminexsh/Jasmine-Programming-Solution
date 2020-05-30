
/*参考修正*/
#include<stdio.h>
int main()
{
    int K;
    scanf("%d\n",&K);
    int A[K];
    int start=0,end=K-1,mid=0;
    int minusnum;
    int Thissum=0,Maxsum=0;
    for(int i=0;i<K;i++)
    {
        if(i!=K-1) scanf("%d ",&A[i]);
        else scanf("%d",&A[i]);
        
        if(A[i]<0) minusnum++;
   
        Thissum+=A[i];
        if(Thissum>Maxsum) 
		{
			Maxsum=Thissum;
			end=i;
			start=mid;
		}
        else if(Thissum<0)
        {
            Thissum=0;
            mid=i+1;
        }
        if(Thissum>Maxsum) 
		{
			Maxsum=Thissum;
			end=A[i];
		}
	}
	
	if(Maxsum==0)
	{
		if(minusnum==K)
		{
			printf("%d %d %d",Maxsum,A[0],A[K-1]);
		}
		else
		{
			printf("%d %d %d",Maxsum,A[mid],A[mid]);
		}
	}
	else
	{
		printf("%d %d %d",Maxsum,A[start],A[end]);
	}
    return 0;
}

  
