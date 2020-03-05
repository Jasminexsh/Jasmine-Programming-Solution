#include <stdio.h>
#include <stdlib.h>

#define N 3000

int main()
{
    int a[N] = {0};
    int b[N] = {0};
    int c[N] = {0};  //求积
    int d[N] = {0};  //求和
    int i ,j;
    int x,z ; //系数  指数
    int cnt=0;

    scanf("%d",&i);  //读入第一个单项式
    while( i-- ){
        scanf("%d %d",&x,&z);
        a[z] += x;   //指数为z的系数放在z位置上
    }

    scanf("%d",&i);  //读入第二个单项式
    while( i-- ){
        scanf("%d %d",&x,&z);
        b[z] += x;
    }

    //多项式乘法
    for( i=N-1; i>=0; i--)
    {
        if( a[i] ){
            for( j=0; j<N; j++){
                if( b[j]){
                    c[ i+j ] += a[i]*b[j];
                }
            }
        }
    }

    //输出多项式乘法结果
    for( i=N-1; i>=0; i--){

        if( c[i] ){
            if( cnt ){
                //处理结尾不能有多余空格
                printf(" ");
            }
            printf("%d %d",c[i],i);
            cnt++;
        }
    }
    if( !cnt ){
        printf("0 0");
    }
    printf("\n");

    //多项式加法
    for( i=N-1; i>=0; i--){
        if( a[i]){
            d[i] += a[i];
        }
    }
    for( j=N-1; j>=0; j--){
        if( b[j]){
            d[j] += b[j];
        }
    }

    //输出多项式加法结果
    cnt = 0;
    for( i=N-1; i>=0; i--){
        if( d[i] ){
            if( cnt ){
                printf(" ");
            }
            printf("%d %d",d[i],i);
            cnt++;
        }
    }
    if(!cnt){
        printf("0 0");
    }

    return 0;
}
