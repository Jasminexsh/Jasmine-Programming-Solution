/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* p;
    struct ListNode* temp;
    p=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->next=head;
    
    while(p->next)
    {
        if(p->next->val==val)
        {
            if(p->next==head)
            {
                temp=head;
                head=head->next;
            }
            else
            {
                temp=p->next;
                p->next=p->next->next;
                
            }
        }
        else
        {
            p=p->next;
        }
    }
    return head;
}
