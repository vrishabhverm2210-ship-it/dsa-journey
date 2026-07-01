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
13void reverse(ListNode*  head,int times){
14    ListNode* curr=head;
15    ListNode* prev=NULL;
16    while(times--){
17        ListNode* next=curr->next;
18        curr->next=prev;
19        prev=curr;
20        curr=next;
21    }
22
23}
24    ListNode* reverseKGroup(ListNode* head, int k) {
25        if(head==NULL)return NULL;
26        ListNode* left=head;
27        ListNode* right=NULL;
28        ListNode* prevleft=NULL;
29        ListNode* res=NULL;
30        while(true){
31            right=left;
32            for(int i=0;i<k-1;i++){
33                if(right==NULL)break;
34            
35            right=right->next;
36            }
37        // Once we able to find right then normal logic
38        if(right){
39            ListNode* nextleft=right->next;
40            reverse(left,k);
41            if(prevleft){
42                prevleft->next=right;
43            }
44            prevleft=left;
45            if(res==NULL)res=right; // storing first right for returning the answer
46
47            left=nextleft;
48        }
49        else{  // right nhi find kr paye
50        if(prevleft){
51            prevleft->next=left;
52        }
53        if(res==NULL)res=left;
54        break;
55  }
56       }
57        return res;
58    }
59};