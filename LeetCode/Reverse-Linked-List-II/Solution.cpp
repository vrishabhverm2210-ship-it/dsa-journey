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
13    ListNode* reverseBetween(ListNode* head, int left, int right) {
14        if(left==right)return head;
15        if(head==NULL )return NULL;
16        int count=1;
17        ListNode *t=head;
18        ListNode *begin=NULL;
19        while(count<left){
20            begin=t;
21            t=t->next;
22            count++;
23        }
24        // now we have reached to the proper position for reversal
25        int times=right-left+1 ; // prev ki position ke hisab se
26         ListNode *curr=t;
27         ListNode *prev=NULL;
28         while(times--){
29            // if(curr==NULL)break;
30             ListNode *next=curr->next;
31            
32             curr->next=prev;
33             prev=curr;
34             curr=next;
35         }
36
37         // now we just have to do the connections
38         t->next=curr;
39         if(begin){
40            begin->next=prev;
41            return head;
42         }
43         return prev;
44
45    }
46};