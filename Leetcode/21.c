/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l;
    l=(struct ListNode*)malloc(sizeof(struct ListNode));
    l=head;

    if(!l1) return l2;
    else if(!l2) return l1;

    while(l1 && l2)
    {
        if(l1->val<l2->val)
        {
            l->next=l1;
            l1=l1->next;
        }
        else
        {
            l->next=l2;
            l2=l2->next;
        }
        l=l->next;
    }
    if(l1)
    {
        l->next=l1;
    }
    if(l2)
    {
        l->next=l2;
    }
    return head->next;
}
