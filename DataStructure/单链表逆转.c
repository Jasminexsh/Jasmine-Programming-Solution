/*
逆转单链表：
函数接口定义：List Reverse( List L );
list的结构定义：
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; // 存储结点数据 
    PtrToNode   Next; // 指向下一个结点的指针 
};
typedef PtrToNode List; // 定义单链表类型 
*/

/*
裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); // 细节在此不表 
void Print( List L ); // 细节在此不表 

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

// 你的代码将被嵌在这里 
*/

List Reverse( List L )
{
    List next;
    List pre=NULL;

    while(L)
    {
        next=L->Next;
        L->Next=pre;
        pre=L;
        L=next;
    }
    return pre;
}
