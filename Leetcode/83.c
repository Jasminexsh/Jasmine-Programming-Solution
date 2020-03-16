/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *Now,*Next;
    struct ListNode* Temp;
    if(!head) //如果传入的是空链表
    {
        return head;
    }
    else //如果传入的链表非空
    {
        Now=head;//初始化Now指针
        Next=head->next;//初始化Next指针
        while(Next)
        {
            while(Next && Now->val==Next->val)
            //若两个指针指向的元素值相等，删除Next指针指向的元素，指针后移
            {
                Temp=Next;
                Next=Next->next;
                Now->next=Next;
                free(Temp);
            }
            if(Next)//如果指针Nezt指针非空，Now与Next指针均向后移一位
            {
                Now=Now->next;
                Next=Next->next;
            }
        }
    }
    return head;
}
