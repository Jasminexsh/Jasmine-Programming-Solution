#include<stdio.h>
int main()
{
  int a,b;
	scanf("%d %d",&a,&b);
  int c = a+b;
  int d = c;
  if(c<1000 && c>-1000)
  {
    printf("%d",c);
  }
  else
  {
    int count=0;
    while(d!=0)
    {
      d/=10;
      count++;
    }
    int number[count];
    if(c<0)
    {
      c=-c;
      printf("-");
    }
    for(int j=count-1;j>=0;j--)
    {
      number[j]=c%10;
      c=c/10;
    }
    int reminder = count%3;
    int digit=0;
    for(int k=0;k<count;k++)
    {
      printf("%d",number[k]);
      digit++;
      if(digit%3==reminder && digit<count)
      {
        printf(",");
      }
    }
  }
  return 0;
}
