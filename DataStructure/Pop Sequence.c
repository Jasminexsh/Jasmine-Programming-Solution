#include<stdio.h>
#define MAX 1001

int M;
int N;
int K;
int stack[MAX],top=0,now=1;

int pushseq[MAX][MAX];
int seq(int *);

int main(){
    int i,j;
    scanf("%d %d %d",&M,&N,&K);
    for(i=0;i<K;i++)
        for(j=0;j<N;j++) scanf("%d",&pushseq[i][j]);
     for(i=0;i<K;i++){
        //初始化栈
        top=0;now=1;
        if( seq(pushseq[i]) ) printf("YES\n");
        else printf("NO\n");
    }
}

int seq(int *pushseq){
    int i;//delete
    while( !top || *pushseq>stack[top])
            stack[++top]=now++;
    //now top get max
    if(top>M || *pushseq<stack[top]) return 0;
    // *pushseq==stack[top] pop element
    top--;pushseq++;
    if(*pushseq) seq(pushseq);
    else return 1;
}

/*
#include <stdio.h>
#include <stdlib.h>
 
#define ERROR -1;
typedef int ElementType;
 
typedef int Position;
typedef int bool;
 
typedef struct SNode * PtrToSNode;
typedef PtrToSNode Stack;
struct SNode{
    ElementType *Data;//存储元素的数组
    Position Top;//栈顶指针
    int MaxSize;//堆栈最大容量
};
 
Stack CreateStack(int MaxSize){
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(sizeof(ElementType)*MaxSize);
    S->MaxSize = MaxSize;
    S->Top = -1;
    return S;
}
 
bool IsFull(Stack S){
    return (S->Top == S->MaxSize -1);
}
 
bool IsEmpty(Stack S){
    return (S->Top == -1);
}
 
bool Push(Stack S,ElementType X){
    if(IsFull(S)){
        printf("堆栈满");
        return 0;
    }else{
        S->Data[++(S->Top)] = X;
        return 1;
    }
}
 
ElementType Pop(Stack S){
    if(IsEmpty(S)){
        printf("堆栈空");
        return ERROR;
    }else{
        return (S->Data[(S->Top)--]);
    }
}
 
int IsTrue(Stack stack, int row[], int length) {
    int flag = 1;
    int pushIdx = 0;//一个push角标
    for(int i=0;i<length;i++){//i其实就是pop角标
        int currentPop = row[i];//当前回合应该pop的值
        //如果push角标小于该值，比如第一个应该pop的值是3，就应该push进去1,2,3,然后才能实现pop出3，第二个应该pop的值是5，就应该push进去4,5，然后才能实现pop出5的需求
        while(pushIdx<currentPop && !IsFull(stack)){
            Push(stack,pushIdx+1);
            pushIdx++;
        }
        //如果实际pop的值不等于应该pop的值，说明无法实现这种需求,则返回失败0
        if(Pop(stack) != currentPop){
            flag = 0;
            break;
        }
    }
    stack->Top = -1;//清空栈
    return flag;
}
 
int main() {
    int size, num, rows;
    scanf("%d %d %d\n", &size, &num, &rows);
    int arr[rows][num];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &(arr[i][j]));
        }
    }

    Stack stack = CreateStack(size);
    
    for (int i = 0; i < rows; i++) {
        int result = IsTrue(stack, arr[i], num);
        if (result) {
            printf("YES");
        } else {
            printf("NO");
        }
        if(i != rows-1){
            printf("\n");
        }
    }  
    return 0;
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct Stack *List;
struct Stack
{
    int data[MAXSIZE];
    int top;
};
int main()
{
    int m,n,k,flag=0;
    scanf("%d %d %d",&m,&n,&k);
    while(k--)
    {
        int num=n,x;
        int now=1;
        flag=0;
        List s;
        s=(List)malloc(sizeof(struct Stack));
        s->top=0;
        while(num--)
        {
             scanf("%d",&x);
             while((s->top==0||s->data[s->top]!=x)&&flag!=1)//空/顶部元素不符合/没超最大内存
             {
                s->data[++(s->top)]=now;
                now+=1;
                if(s->top>m)
                {
                    flag=1;//溢出
                    break;
                }
             }
             if(s->data[s->top]==x&&flag!=1)
             {
                   s->top--;
 
             }
        }
        if(flag==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
*/
