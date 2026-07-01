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
13    ListNode* reverseList(ListNode* head) {
14        //base case
15        if(head==NULL||head->next==NULL){
16            return head;
17        }
18         ListNode* curr=head;
19          ListNode* prev=NULL;
20           
21
22        while(curr!=NULL){
23            ListNode* forward=curr->next;
24            curr->next=prev;
25            prev=curr;
26            curr=forward;
27        }   
28
29        return prev;  
30
31
32
33
34
35    }
36};