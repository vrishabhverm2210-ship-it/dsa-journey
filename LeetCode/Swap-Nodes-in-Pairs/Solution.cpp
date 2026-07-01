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
13void reverse(ListNode* head,int times){
14    ListNode* curr=head;
15    ListNode* prev=NULL;
16    while(times--){
17        ListNode * next=curr->next;
18        curr->next=prev;
19        prev=curr;
20        curr=next;
21    }
22}
23    ListNode* swapPairs(ListNode* head) {
24        if(head==NULL)return NULL;
25        ListNode* left=head;
26        ListNode* right=NULL;
27        int size=2;
28        ListNode* prevleft=NULL;
29        ListNode* res=NULL;
30        while(true){
31            right= left;
32            for(int i=0;i<size-1;i++){
33                if(right==NULL){
34                break;
35            }
36                right=right->next;
37            }
38            // firstly store next left
39            if(right){
40            ListNode * nextleft=right->next;
41            reverse(left,size);
42              if(prevleft){
43                prevleft->next=right;     
44              }
45            prevleft=left;
46              if(res==NULL)res=right; // storing the first one
47
48              left=nextleft;
49            }
50            else{// right na aa paya (single node left)
51            if(prevleft){
52                prevleft->next=left; // curr vale left ko prevleft se jod dia 
53            }
54
55                if(res==NULL)res=left;  // if single node hoti
56
57                break;
58            }
59         }
60                 
61        
62
63        return res;
64        
65    }
66};