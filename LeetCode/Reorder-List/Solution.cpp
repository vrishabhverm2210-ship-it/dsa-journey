1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13void reverse1(ListNode* head,ListNode* &prev){
14    while(head!=NULL){
15        ListNode* next=head->next;
16        head->next=prev;
17        prev=head;
18        head=next;
19    }
20}
21    void reorderList(ListNode* head) {
22        // find middle
23        ListNode* slow=head;
24        ListNode* fast=head;
25        while(fast!=NULL && fast->next!=NULL)
26        {
27            slow=slow->next;
28            fast=fast->next->next;
29        }
30        ListNode* prev=NULL;
31    ListNode* second = slow->next;
32slow->next = NULL;
33reverse1(second, prev);
34        // till  now we have two list and now we have to merge it alternatively
35
36        ListNode* temp1=head;
37        ListNode* temp2= prev;
38        
39        while( temp2!=NULL){
40            ListNode* next1=temp1->next;
41        ListNode* next2=temp2->next;
42        temp1->next=temp2;
43        temp2->next=next1;
44        temp2=next2;
45        temp1=next1;
46        }
47    }
48};