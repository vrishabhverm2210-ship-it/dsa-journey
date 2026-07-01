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
13ListNode* kreverse(ListNode* head, int k){
14    // base case
15    if(head==NULL){
16        return NULL;
17    }
18    int count=0;
19      ListNode* temp= head;
20      while(temp!=NULL){
21        count++;
22        temp=temp->next;
23      }
24      if(count<k){
25        return head;
26      }
27
28    ListNode* curr=head;
29    ListNode* prev=NULL;
30    ListNode* next=NULL;
31    int revcount=0;
32    while(curr!= NULL&& revcount<k){
33   next=curr->next;
34   curr->next=prev;
35   prev=curr;
36   curr=next;
37   revcount++;
38    }
39    if(next!=NULL){
40        head->next= kreverse(next,k);
41
42    }
43  return prev;
44}
45
46    ListNode* reverseKGroup(ListNode* head, int k) {
47         return kreverse(head,k);
48    }
49};