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
13struct emp{
14    bool operator()(ListNode* &a , ListNode* &b){
15        return a->val>b->val;
16    }
17};
18    ListNode* mergeKLists(vector<ListNode*>& lists) {
19        priority_queue<ListNode*,vector<ListNode*>,emp>pq;
20
21        for(int i=0;i<lists.size();i++){
22                if(lists[i] != NULL) {
23
24            pq.push(lists[i]);
25                }
26        }
27ListNode* head=NULL;
28ListNode* tail=NULL;
29    while(!pq.empty()){
30        ListNode* node=pq.top();
31        pq.pop();
32        if(node->next!=NULL)pq.push(node->next);
33        if(head==NULL){
34            head=node;
35            tail=node;
36        }
37        else{
38            tail->next=node;
39            tail=tail->next;
40        }
41
42    }
43return head;
44    }
45};