1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    ListNode *detectCycle(ListNode *head) {
12        ListNode * slow=head;
13        ListNode * fast=head;
14        while(fast!=NULL && fast->next!=NULL){
15            slow=slow->next;
16            fast=fast->next->next;
17            if(slow==fast){
18                slow=head;
19                while(slow!=fast){
20                    slow=slow->next;
21                    fast=fast->next;
22                }
23                return slow;
24            }
25        }
26        return NULL;
27    }
28};