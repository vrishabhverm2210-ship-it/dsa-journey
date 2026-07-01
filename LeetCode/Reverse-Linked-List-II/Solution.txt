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
14        // firstly write base cases
15        if(left==right)return head;
16        if(head==NULL) return NULL;
17         ListNode* t=head;
18         int pos=1;
19          ListNode* begin=NULL;
20
21        while(pos < left){
22           begin = t;
23           t = t->next;
24           pos++;
25}
26         
27         int times=right-left+1;
28         // once hum rev valli site pe pahuch gaye
29          ListNode* curr=t;
30           ListNode* prev=NULL;
31           while(times--){ // NO of times reverse process should taken place
32          ListNode* next= curr->next;
33        curr->next=prev;
34        prev=curr;
35        curr=next;
36           }
37           // now the part we have to reverse is done(now we have to just link the connections)
38           t->next=curr;
39           if(begin){
40           begin->next=prev;
41           return head;
42           }
43           return prev;
44
45    }
46};