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
14         ListNode* curr=head;
15          ListNode* prev=NULL;
16          while(curr!=NULL){
17             ListNode* nextt=curr->next;
18             curr->next=prev;
19             prev=curr;
20             curr=nextt;
21          }
22          return prev;
23    }
24};