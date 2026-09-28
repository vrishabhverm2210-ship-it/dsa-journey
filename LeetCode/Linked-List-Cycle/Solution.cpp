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
11    bool hasCycle(ListNode *head) {
12        if(head==NULL)return false;
13        ListNode *slow=head;
14        ListNode *fast=head;
15        while(fast->next!=NULL&& fast->next->next!=NULL){
16               slow=slow->next;
17               fast=fast->next->next;
18               if(slow==fast)return true;
19        }
20        return false;
21    }
22};