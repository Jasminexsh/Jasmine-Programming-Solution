/*参考学习 理解代码逻辑*/
/*
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int Address;
	int Data;
	int Next;
}list;

void Array(list a[], int N, int headaddress);
void Exchange(list a[], int i, int j);
void Reverse(list a[], int N, int K);

int main(){
	int K, N, headaddress, eff;
	scanf("%d %d %d", &headaddress, &N, &K);
	list a[N];
	for (int i = 0; i<N; i++) {
		scanf("%d %d %d", &a[i].Address, &a[i].Data, &a[i].Next);
	}
	Array(a, N, headaddress);
	for (int i = 0; i<N; i++) {
		if (a[i].Next == -1) {
			eff = i + 1;
		}
	}
	Reverse(a, eff, K);
	for (int i = 0; i<eff; i++)	{
		a[i].Next = a[i + 1].Address;
		if (i == eff - 1) {
			a[i].Next = -1;
		}
	}
	for (int i = 0; i<eff - 1; i++) {
		printf("%05d %d %05d\n", a[i].Address, a[i].Data, a[i].Next);
	}
	printf("%05d %d %d\n", a[eff - 1].Address, a[eff - 1].Data, -1);
	return 0;
}


void Array(list a[], int N, int headaddress) {
	for (int i = 0; i<N; i++) {
		if (a[i].Address == headaddress) {
			Exchange(a, i, 0);
			break;
		}
	}
	for (int i = 0; i<N; i++) {
		for (int j = i + 1; j<N; j++) {
			if (a[i].Next == a[j].Address) {
				Exchange(a, i + 1, j);
				break;
			}
		}
	}
}


void Exchange(list a[], int i, int j) {
	list temp;
	temp.Address = a[j].Address;
	temp.Data = a[j].Data;
	temp.Next = a[j].Next;
	a[j].Address = a[i].Address;
	a[j].Data = a[i].Data;
	a[j].Next = a[i].Next;
	a[i].Address = temp.Address;
	a[i].Data = temp.Data;
	a[i].Next = temp.Next;
}

void Reverse(list a[], int N, int K) {
	int cnt = N / K;
	if (cnt) {
		for (int j = 1; j <= cnt; j++) {
			for (int i = 1; i <= K; i++) {
				if ((j - 1)*K + i - 1 <= j * K - i - 1) {
					Exchange(a, (j - 1)*K + i - 1, j*K - i);
				}
			}
		}
	}
}
*/

#include<stdio.h>
#include<stdlib.h>
#ifndef NULL
#define NULL 0
#endif // NULL
#define MAXSIZE 100000

typedef struct Node *PtrToNode;
struct Node
{
    int Address;
    int Data;
    int Next;
    struct Node *Next_id;
};

typedef PtrToNode List;
List CreateList(int N, int FirstAddr);
void ListReverse(List L, int K);
PtrToNode Reverse(PtrToNode Head, int K);
void printList(List L);
List SortList(int *data, int *next, int FirstAddr);
PtrToNode CreateNode(int Address,int Data,int Next);

int main()
{
    int N,K;
    int FirstAddr;
    List L;

    scanf("%d %d %d", &FirstAddr, &N, &K);
    L = CreateList(N, FirstAddr);
    ListReverse(L,K);
    printList(L);
}

List CreateList(int N, int FirstAddr)
{
    int data[MAXSIZE];
    int next[MAXSIZE];
    int i, address;
    List L;
    for(i=0;i<N;i++)
    {
        scanf("%d", &address);
        scanf("%d %d", &data[address], &next[address]);
    }
    //建立头结点
    L = SortList(data, next, FirstAddr);
    return L;
}

List SortList(int *data, int *next, int FirstAddr)
{
    List L,tmp,ptr;
    L = (List)malloc(sizeof(struct Node));
    L->Address = L->Data = L->Next = -1;
    L->Next_id = NULL;
    if(FirstAddr == -1)
        return L;
    else if(FirstAddr > -1)
    {
        tmp = CreateNode(FirstAddr,data[FirstAddr],next[FirstAddr]);
        L->Next = FirstAddr; L->Next_id = tmp;
        ptr = L->Next_id;
        while(ptr->Next > -1)
        {
            tmp = CreateNode(ptr->Next,data[ptr->Next],next[ptr->Next]);
            ptr->Next_id = tmp;
            ptr = ptr->Next_id;
        }
        return L;
    }
    else
        return NULL;
}

PtrToNode CreateNode(int address,int data,int next)
{
    PtrToNode node;
    node = (PtrToNode)malloc(sizeof(struct Node));
    node->Address = address;
    node->Data = data;
    node->Next = next;
    node->Next_id = NULL;
    return node;
}

void ListReverse(List L,int K)
{
    if(K == 1)
        return;
    int n = 0, circle,i,j;//n 链表的元素数量
    PtrToNode ptr, new_node;
    ptr = L;
    while(ptr->Next_id)
    {
        n++;
        ptr = ptr->Next_id;
    }
    if(n == 0)
        return;
    else
        circle = n/K;//需要翻转的次数
    ptr = L;
    for(i=0;i<circle;i++)
    {
        new_node = Reverse(ptr,K);
        ptr = new_node;
        for(j = 1;j<K;j++){
            ptr = ptr->Next_id;
        }
    }
    return;
}

PtrToNode Reverse(PtrToNode Head, int K)
{
    int cnt = 1;
    PtrToNode New_node, Old_node, tmp;
    New_node = Head->Next_id;
    Old_node = New_node->Next_id;
    while(cnt < K)
    {
        tmp = Old_node->Next_id;
        Old_node->Next_id = New_node;
        New_node = Old_node;Old_node = tmp;
        cnt++;
    }

    Head->Next_id->Next_id = Old_node;
    Head->Next_id = New_node;
    return New_node;
}

void printList(List L)
{
    PtrToNode ptr;
    ptr = L->Next_id;
    while(ptr)
    {
        if(!ptr->Next_id)
            printf("%.5d %d -1\n",ptr->Address,ptr->Data);
        else
            printf("%.5d %d %.5d\n",ptr->Address,ptr->Data,ptr->Next_id->Address);
        ptr = ptr->Next_id;
    }
}
