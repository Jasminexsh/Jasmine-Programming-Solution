#include<stdio.h>
#include<string.h>
int main()
{
    char k[1000];
    scanf("%s",k);
    int num[10]={0};
    for(int i=0;i<strlen(k);i++)
    {
        switch(k[i]-'0')
        {
            case 0:
                num[0]+=1;
                break;
            case 1:
                num[1]+=1;
                break;
            case 2:
                num[2]+=1;
                break;
            case 3:
                num[3]+=1;
                break;
            case 4:
                num[4]+=1;
                break;
            case 5:
                num[5]+=1;
                break;
            case 6:
                num[6]+=1;
                break;
            case 7:
                num[7]+=1;
                break;
            case 8:
                num[8]+=1;
                break;
            case 9:
                num[9]+=1;
                break;
        }
    }
    for(int j=0;j<10;j++)
    {
        if(num[j]!=0)
        {
            printf("%d:%d\n",j,num[j]);
        }
        else
        {
            continue;
        }
    }
    return 0;
}
