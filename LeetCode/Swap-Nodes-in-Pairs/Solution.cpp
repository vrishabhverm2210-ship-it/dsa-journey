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
13void reverse(ListNode *head,int times){
14    ListNode *curr=head;
15    ListNode *prev=NULL;
16    while(times--){
17        ListNode *next=curr->next;
18        curr->next=prev;
19        prev=curr;
20        curr=next;
21    }
22}
23    ListNode* swapPairs(ListNode* head) {
24          ListNode *left=head;
25            ListNode *right=NULL;
26         ListNode *prevleft=NULL;
27         int size=2;
28         ListNode *res=NULL;
29         while(true){
30             right=left;
31         for(int i=0;i<size-1;i++){
32            if(right==NULL){
33            // right=NULL;
34            break;  // remember the last one case when there is no right
35            }
36            right=right->next;
37         }
38         if(right){
39             ListNode *nextleft=right->next;
40             reverse(left,2);
41             if(prevleft){
42                prevleft->next=right;
43             }
44             prevleft=left;
45             if(res==NULL)res=right;
46             
47
48             left=nextleft;
49         }
50         else{
51            if(prevleft){
52                prevleft->next=left;
53                break;
54                }
55            
56            if(res==NULL)res=left; 
57            break;  
58         }
59       }
60         return res;
61    }
62};