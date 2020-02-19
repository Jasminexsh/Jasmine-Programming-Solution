#include<stdio.h>

int main()
{
  int K;
	scanf("%d\n",&K);
	int A[K];
	int start,end;
	int sum=0,max=0,maxseq[K]={0};
	int minus=0;
	
	for(int i=0;i<K;i++)
	{
		if(i!=K-1) scanf("%d ",&A[i]);
		else scanf("%d",&A[i]);
	
		if(A[i]<0) minus++;
		
		if(sum+A[i]>=0)
		{
			sum+=A[i];
			maxseq[i]=A[i];
			if(sum>max)
			{
				max=sum;
			}
		}
		else 
		{
			sum=0;
		}
  }
	//搜索最长子列和的首尾元素 
	int count=0,temp;
	for(int k=0;k<K;k++)//搜索最长子列和的尾元素 
	{
		if(A[k]>=0)
		{
			count+=maxseq[k];
			if(count==max)
			{
				end=maxseq[k];
				temp=k;
				break;
			}
		}
		else count=0;
	}
	
	while(A[temp-1]>=0)//搜索最长子列和的首元素 
	{
		temp--;
	}
	start=maxseq[temp];
	
	if(max!=0) printf("%d %d %d",max,start,end);
	else if(minus==K) printf("%d %d %d",max,A[0],A[K-1]);
  else printf("%d %d %d",max,0,0);
	return 0;

/*参考修正
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
*/
  
